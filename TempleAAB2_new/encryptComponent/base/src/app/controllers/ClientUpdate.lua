--[[
 	下载更新
 		2016_04_27 C.P
 	功能：下载替换文件资源
]]--
local ClientUpdate = class("ClientUpdate")

-- url:下载list地址 
-- wirtepath:保存路径
-- curfile:当前list路径
--moduleName 为base,client gamename
local notHotFile = {
	"base/src/app/models/ylAll.lua",
	"base/src/config.lua"
}

local MaxDownCount                              = 5             --最大下载的个数

function ClientUpdate:ctor(newfileurl,savepath,curfile,downurl,moduleName,curMoudleVersion)
	self._newfileurl = newfileurl
	self._savepath = savepath
	self._curfile = curfile
	self._downUrl = downurl
    self._moduleName = moduleName
    self._curMoudleVersion = curMoudleVersion
	self._curDownCount = 0
	self._totalDownCount = 0 
	self._needDownCount = 0
	self._downFileName = {}  --已经下载好的文件名
	self._timeOutFileName = {}  --超时为下载的文件名
	self._timeOutQuit = true
end

--开始更新 
--listener回调目标
--listener:updateProgress(sub,msg)
--listener:updateResult(result,msg)
function ClientUpdate:upDateClient(listener)
	--监听
	self._listener = listener
	self._downList={}			--下载列表
	self._downListCpy = {}      --下载列表 多保存一份，做校验用
	local this = self
	local result = false
	local msg = nil

	while(not result)
	do
		--创建文件夹
		if not createDirectory(self._savepath) then
			msg = "创建文件夹失败！"
			break
		end
        local isUpdateZip = false
        if not cc.FileUtils:getInstance():isFileExist(self._curfile) or self._curMoudleVersion == nil then
           isUpdateZip = true
        end
        local serverModuleVersion = ylAll.SERVER_UPDATE_DATA[self._moduleName.."_zip"] or 0
        if not isUpdateZip and self._curMoudleVersion and serverModuleVersion and self._curMoudleVersion < serverModuleVersion then
            isUpdateZip = true
        end

        --本地是否有json文件，没有的话 下载zip
        if isUpdateZip then
            downFileAsync(self._downUrl..self._moduleName..".zip",self._moduleName..".zip",self._savepath,function(main,sub) 
	        	if main == appdf.DOWN_PRO_INFO then --进度信息
					if this._listener and not tolua.isnull(this._listener) then
	        			this._listener:updateProgress(nil,nil,sub)
					end
	        	elseif main == appdf.DOWN_COMPELETED then --下载完毕
                    local vision = ylAll.SERVER_UPDATE_DATA[self._moduleName.."_zip"] or 0
					if this._listener and not tolua.isnull(this._listener) then
                    	this._listener:upDateSuccessToUnzip(self._savepath..self._moduleName..".zip",self._savepath,self._moduleName,vision)
					end
                else
					if this._listener and not tolua.isnull(this._listener) then
                    	this._listener:updateResult(false,"Download falhou,main:" .. main) --失败信息
					end
                end
            end)  
            return           
        end
		--获取当前文件列表
		local szCurList = cc.FileUtils:getInstance():getStringFromFile(self._curfile)
        dump(szCurList)
		local oldlist = {}
		if  szCurList ~= nil and #szCurList > 0 then
			local curMD5List = cjson.decode(szCurList)
			oldlist = curMD5List["listdata"]
		end		
		appdf.onHttpJsonTable(self._newfileurl,"GET","",function(jsondata,response)
				--记录新的list
				local fileUtil = cc.FileUtils:getInstance()
				this._response = response
				if jsondata then
					local newlist = jsondata["listdata"]
					if nil == newlist and this._listener and not tolua.isnull(this._listener) and nil ~= this._listener.updateResult then
						this._listener:updateResult(false,"Falha ao obter a lista de servidores!")
						return
					end
					--删除判断
					for k,v in pairs(oldlist) do
						local oldpath = v["path"]
						local oldname = v["name"]
						if  oldpath then
							local bdel = true
							for newk,newv in pairs(newlist) do
								if oldpath == newv["path"] and oldname == newv["name"] then
									bdel = false
									break
								end
							end
							--删除文件
							if bdel == true then
								print("removefile:"..self._savepath..oldpath..oldname)
								if this:checkFileUpdate(oldpath..oldname) then
									fileUtil:removeFile(self._savepath..oldpath..oldname)
								end
							end
						end
					end
					--下载判断
					for k ,v in pairs(newlist) do
						local newpath = v["path"]
						if newpath then
							local needupdate = true
							local newname = v["name"]
							local newmd5 = v["md5"]
							for oldk,oldv in pairs(oldlist) do
								local oldpath = oldv["path"]
								local oldname = oldv["name"]
								local oldmd5 = oldv["md5"]
								
								if oldpath == newpath and newname == oldname then 
									if newmd5 == oldmd5 then
										needupdate = false
                                    end
									break
								end
							end
							--保存到下载列队
							if needupdate == true then
								if this:checkFileUpdate(newpath..newname) then
									table.insert(this._downList , {newpath,newname,newmd5})	
									table.insert(this._downListCpy , {newpath,newname,newmd5})
								end					
							end
						end
						
					end
					print("update_count:"..#this._downList)
					for i, v in ipairs(this._downList) do
						print("i =",i," v =",v[1]..v[2])
					end
					--开始下载
					if #this._downList >0 then
						this._downIndex = 1
						this._totalDownCount = #this._downList
						this._needDownCount = this._totalDownCount
						this:UpdateFile()
					else
						cc.FileUtils:getInstance():writeStringToFile(self._response,self._curfile)
						if this._listener and not tolua.isnull(this._listener) then
							this._listener:updateResult(true,"")
						end
					end
				else
					if this._listener and not tolua.isnull(this._listener) then
						this._listener:updateResult(false,"Falha ao obter a lista de servidores!")
					end
				end
			end)

		result = true
	end
	if not result then
		listener:updateResult(false,msg)
	end

end
--下载
function ClientUpdate:UpdateFile()
	local this = self
	-- while this._curDownCount < ylAll.MaxDownCount and (#this._downList > 0 or #this._timeOutFileName > 0) do
	while this._curDownCount < MaxDownCount and (#this._downList > 0 or #this._timeOutFileName > 0) do
		 this._curDownCount = this._curDownCount + 1
		 local fileinfo = table.remove(self._downList)
		 if fileinfo == nil then 
			fileinfo = table.remove(self._timeOutFileName) 
		 end
		 local url = self._downUrl..fileinfo[1]..fileinfo[2]
		 local dstpath = self._savepath..fileinfo[1]
		--调用C++下载
		downFileAsync(url,fileinfo[2],dstpath,function(main,sub,filename)
			if main == appdf.DOWN_PRO_INFO then --进度信息
				if this and this._listener and not tolua.isnull(this._listener) then
				    this._listener:updateProgress(sub,fileinfo[2], (this._downIndex / self._needDownCount) * 100)
				end	 
			elseif main == appdf.DOWN_COMPELETED then --下载完毕
				this._totalDownCount = this._totalDownCount - 1
				this._curDownCount = this._curDownCount - 1
				this._downIndex = this._downIndex + 1
				if(this._curDownCount < 0)then this._curDownCount = 0 end
				--table.insert(this._downFileName,this:onGetFileInfo(filename))
				if this._totalDownCount == 0 then
					this:onDownSuccess()  --下载完成
			    else
					this:UpdateFile()
			    end
			else
				if sub == 28 then  --超时继续下载
					table.insert(this._timeOutFileName,this:onGetFileInfo(filename))
					this._curDownCount = this._curDownCount - 1
					if this._curDownCount < 0 then this._curDownCount = 0 end
				    this:UpdateFile()	
				else
					if this._timeOutQuit == true and this and this._listener and not tolua.isnull(this._listener) then
						this._timeOutQuit = false
					    this._listener:updateResult(false,"The download failed,main:" .. main .. " ## sub:" .. sub) --失败信息
					end
				end
			end	
		end)
	end
end
function ClientUpdate:onDownSuccess()
	self._totalDownCount = -1
	cc.FileUtils:getInstance():writeStringToFile(self._response,self._curfile)--更新本地MD5
	--通知完成
	if self._listener and not tolua.isnull(self._listener) then
		self._listener:updateResult(true,"")
	end
	return 
end
function ClientUpdate:onGetFileInfo(fileName)
	for i,v in pairs(self._downListCpy) do
		if v[2] == fileName then
			return v
		end
	end
end
function ClientUpdate:checkFileUpdate(fileName)
	for k = 1,#notHotFile do
		if notHotFile[k] == fileName then
			return false
		end
	end
	return true
end

return ClientUpdate
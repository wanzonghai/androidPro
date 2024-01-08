import DataManager from "./DataManager";
import GameWheel from "./GameWheel";
import ItemNode from "./ItemNode";
import NativeUtil from "./util/NativeUtil";
import { DirectionType, EventId } from "./util/define";
import EventMgr from "./util/event/EventMgr";
import loaderManager from "./util/loaderManager";
import util from "./util/util";


const { ccclass, property } = cc._decorator;

@ccclass
export default class GameLayer extends cc.Component {

    @property({ type: [cc.SpriteFrame], tooltip: "元素纹理" })
    itemResList: cc.SpriteFrame[] = [];

    @property({ type: cc.Node, tooltip: "用户余额节点" })
    userCoinNode: cc.Node = null

    @property({ type: cc.Node, tooltip: "游戏提示页面" })
    tipNode: cc.Node = null

    @property({ type: cc.Node, tooltip: "游戏结果节点" })
    resultNode: cc.Node = null

    @property({ type: cc.Node, tooltip: "倒计时节点" })
    timerNode: cc.Node = null

    @property({ type: cc.Node, tooltip: "音效按钮节点" })
    soundBtn: cc.Node = null

    @property({ type: cc.Node, tooltip: "音效按钮节点" })
    musicBtn: cc.Node = null

    @property({ type: cc.Node, tooltip: "开始游戏节点" })
    playBtn: cc.Node = null

    @property({ type: cc.Node, tooltip: "游戏格子" })
    gzPos: cc.Node = null

    @property({ type: cc.Node, tooltip: "游戏格子" })
    gamePos: cc.Node = null

    @property({ type: cc.Node, tooltip: "玩家绘制展示节点" })
    playDrawShowNode: cc.Node = null;

    @property({ type: cc.Node, tooltip: "线展示节点" })
    lineShowNode: cc.Node = null;

    @property({ type: cc.Node, tooltip: "线展示节点" })
    keyNode: cc.Node = null;

    @property({ type: [cc.AudioClip] })
    audioResList: cc.AudioClip[] = [];

    /** 上一次绘制的格子 */
    lastDrawCell: cc.Node = null;

    public iconPf: cc.Prefab = null

    public index: number = 0

    private colNum = 7
    private rowNum = 5

    /** 已绘制线数组 */
    alreadyDrawLineList: Array<Array<number>> = [];

    /** 当前绘制线数组 */
    curDrawLineItmeIndex: Array<number> = [];


    list: Array<number> = [];
    /**加载预制体 */
    async loadCard() {
        this.iconPf = await loaderManager.getRes("item", "prefab", cc.Prefab)
        if (this.iconPf) {
            console.log("预制体加载成功！");
        }
    }

    start() {
        this.updateUserCoin();
        this.updateTimerUi()
        this.loadCard()
        // this.listerEvent()
        this.bindingDrawVisualEvent()
    }
    //绑定事件
    listerEvent() {
        EventMgr.Instance.Register(EventId.Result, this.showResult, this)
    }

    /**
     * 清除事件
     */
    cleatEvent() {
        EventMgr.Instance.Off()
    }
    /**
     * 游戏内按钮绑定事件
    */
    btnEvent(event: cc.Event) {
        let name = event.target.name;
        this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
        this.node.getComponent(cc.AudioSource).play();
        switch (name) {
            case "btnStartGame":
                this.playGame();
                break;
            case "btnReturn":
                this.hideResultNode();
                this.cleatEvent()
                cc.director.loadScene("hall");
                break;
            case "btNextGame":
            case "btStartOver":
                this.hideResultNode();
                break;
            case "btExit":
                this.hideResultNode();
                this.cleatEvent()
                cc.director.loadScene("hall");
                break;
            case "tipBtn":
                this.openTipNode()
                break;
            case "closeTipBtn":
                this.hideTipNode();
                break;
            case "btnSound":
                this.openOrCloseSound();
                break;
            case "musicBtn":
                this.openOrCloseBG();
                break;
        }
    }

    /** 开始游戏 */
    playGame() {
        if (DataManager.curGameIsRun) return
        DataManager.curGameIsRun = true;
        // cc.director.getCollisionManager().enabled = true;
        // 计时器
        this.startTimer();
        //隐藏游戏按钮
        // this.playBtn.active = false
        this.node.getComponent(cc.AudioSource).clip = this.audioResList[2];
        this.node.getComponent(cc.AudioSource).play();
        //游戏逻辑

        for (let i = 0; i < this.gzPos.children.length; i++) {
            // if(i == 14 || i == 20){
            //     continue;
            // }
            this.creatBall(this.gzPos.children[i].position, i)

        }
        console.log("初始", this.list);

    }

    /**创建预制体 */
    creatBall(pos: cc.Vec3, i: number) {
        let ballNode = cc.instantiate(this.iconPf)
        let index = util.getRandom(0, ballNode.getComponent(ItemNode).imgSpArr.length - 1)
        let gan = util.getRandom(0, 100)
        if (gan > 80) {
            ballNode.getComponent(ItemNode).init(index, i, true)
        } else {
            ballNode.getComponent(ItemNode).init(index, i, false)
        }
        this.list.push(index);
        ballNode.setParent(this.gamePos)
        ballNode.setPosition(pos)
        // this.listTouchEvent(ballNode)
    }

    /**绑定滑动事件 */
    listTouchEvent(TouchNode: cc.Node) {
        TouchNode.on(cc.Node.EventType.TOUCH_START, (event) => {
            TouchNode["startPos"] = cc.v2(event.getLocation().x, event.getLocation().y)
        })
        TouchNode.on(cc.Node.EventType.TOUCH_CANCEL, (event) => {
            let statPos = TouchNode["startPos"]
            let endPos = cc.v2(event.getLocation().x, event.getLocation().y)
            let direction = this.isDirection(statPos, endPos)
            if (direction) {
                this.TouchMove(TouchNode, direction)
            }
        })
    }


    /**
     * 绘画展示区绑定事件
    */
    bindingDrawVisualEvent() {
        this.playDrawShowNode.on(cc.Node.EventType.TOUCH_START, (even: cc.Event.EventTouch) => {
            // if(DataManager.itemHideAniIsPlay || !DataManager.curGameIsRun) return;
            let curWorldItem: cc.Node = this.getCurWorldPosItem(even.getLocation());
            if (curWorldItem != null) {
                this.curDrawLineItmeIndex = [];
                this.playDrawShowNode["isDraw"] = true;
                this.lastDrawCell = curWorldItem;
                this.curDrawLineItmeIndex.push(curWorldItem.getComponent(ItemNode).itemIndex);
            }
        })
        this.playDrawShowNode.on(cc.Node.EventType.TOUCH_MOVE, (even: cc.Event.EventTouch) => {
            if (!this.playDrawShowNode["isDraw"]) return;

            let curWorldPosItem: cc.Node = this.getCurWorldPosItem(even.getLocation());

            this.playDrawShowNode.getComponent(cc.Graphics).clear();
            if (curWorldPosItem && this.curCellIsDraw(curWorldPosItem)) {
                this.lastDrawCell["alreadyDraw"] = true;
                curWorldPosItem["alreadyDraw"] = true;
                this.drawLine(curWorldPosItem.convertToWorldSpaceAR(cc.v3(0, 0, 0)));
                this.lastDrawCell = curWorldPosItem;
                this.curDrawLineItmeIndex.push(curWorldPosItem.getComponent(ItemNode).itemIndex);
            }
            this.drawPlayVisualLine(even.getLocation());
        })
        this.playDrawShowNode.on(cc.Node.EventType.TOUCH_END, (even: cc.Event.EventTouch) => {
            if (!this.playDrawShowNode["isDraw"]) return;

            this.playDrawShowNode["isDraw"] = false;
            this.playDrawShowNode.getComponent(cc.Graphics).clear();
            this.lineShowNode.getComponent(cc.Graphics).clear();

            if (this.curDrawLineItmeIndex.length >= 3) { // 达到清除条件

                DataManager.itemHideAniIsPlay = true;
                let aniNum = 0;
                let endCall = () => {
                    DataManager.itemHideAniIsPlay = false;
                    this.gamePos.children.forEach(item => {
                        if (item.opacity == 255) {
                            item["alreadyDraw"] = false;
                        }
                    })
                };

                for (let i: number = 0; i < this.curDrawLineItmeIndex.length; i++) {
                    let index = this.curDrawLineItmeIndex[i];
                    let node = this.gamePos.children[index];
                    aniNum += 2;
                    cc.tween(node)
                        .to(0.2, { scale: 1.1 })
                        .call(() => {
                            if (--aniNum == 0) {
                                endCall();
                                node.scale = 1
                            }
                        })
                        .start();
                    cc.tween(node)
                        .to(0.2, { opacity: 0 })
                        .call(() => {
                            if (--aniNum == 0) {
                                endCall();
                            }
                            if (node.getComponent(ItemNode).hasKey == true) {
                                DataManager.keyNum += 1
                            }
                            let itemID = util.getRandom(0, node.getComponent(ItemNode).imgSpArr.length - 1)
                            let gan = util.getRandom(0, 80)
                            if (gan > 80) {
                                node.getComponent(ItemNode).init(itemID, node.getComponent(ItemNode).itemIndex, true)
                            } else {
                                node.getComponent(ItemNode).init(itemID, node.getComponent(ItemNode).itemIndex, false)
                            }
                            node.opacity = 255
                            DataManager._curScord += 30
                            this.updataCoin()
                        })
                        .start();

                }
            } else {
                this.gamePos.children.forEach(item => {
                    if (item.opacity == 255) {
                        item["alreadyDraw"] = false;
                    }
                })
            }
        })
    }
    /**
     * 绘制玩家可视线条
    */
    drawPlayVisualLine(endPos) {
        if (!this.lastDrawCell) return;

        let targetPos = cc.v3(0, 0, 0);
        let startPos = cc.v3(0, 0, 0);
        let graphics = this.playDrawShowNode.getComponent(cc.Graphics);

        startPos = this.playDrawShowNode.convertToNodeSpaceAR(this.lastDrawCell.convertToWorldSpaceAR(cc.v3(0, 0, 0)));
        targetPos = this.playDrawShowNode.convertToNodeSpaceAR(cc.v3(endPos.x, endPos.y));
        graphics.moveTo(startPos.x, startPos.y);
        graphics.lineTo(targetPos.x, targetPos.y);
        graphics.stroke();
    }

    /**
   * 当前格子是否可绘制
  */
    curCellIsDraw(curItem) {
        let lastItemId = this.lastDrawCell.getComponent(ItemNode).itemId;
        let curItemId = curItem.getComponent(ItemNode).itemId;
        if (lastItemId != curItemId || curItem["alreadyDraw"]) return;

        let lastIndex = this.lastDrawCell.getComponent(ItemNode).itemIndex;
        let lastRow = Math.floor(lastIndex / this.colNum);
        let lastCol = lastIndex % this.colNum;
        let curIndex = curItem.getComponent(ItemNode).itemIndex;
        let curRow = Math.floor(curIndex / this.colNum);
        let curCol = curIndex % this.colNum;



        if (curRow == lastRow && (lastCol + 1 == curCol || lastCol - 1 == curCol)) { // 同行
            return true;
        }
        if (curCol == lastCol && (lastRow + 1 == curRow || lastRow - 1 == curRow)) { // 同列
            return true;
        }
        if (curRow == lastRow - 1 && curCol == lastCol + 1) { // 左上
            return true;
        }
        if (curRow == lastRow + 1 && curCol == lastCol + 1) { // 右上
            return true;
        }
        if (curRow == lastRow - 1 && curCol == lastCol - 1) { // 左下
            return true;
        }
        if (curRow == lastRow + 1 && curCol == lastCol - 1) { // 右下
            return true;
        }

        return false;
    }

    /**
     * 绘制结果可视线条
    */
    drawLine(endPos) {
        let targetPos = cc.v3(0, 0, 0);
        let startPos = cc.v3(0, 0, 0);
        let graphics = this.lineShowNode.getComponent(cc.Graphics);
        startPos = this.playDrawShowNode.convertToNodeSpaceAR(this.lastDrawCell.convertToWorldSpaceAR(cc.v3(0, 0, 0)));
        targetPos = this.lineShowNode.convertToNodeSpaceAR(endPos);
        graphics.moveTo(startPos.x, startPos.y);
        graphics.lineTo(targetPos.x, targetPos.y);
        graphics.stroke();
    }


    /**移动事件 */
    TouchMove(taget: cc.Node, direction: DirectionType) {
        let itemId = taget.getComponent(ItemNode).itemIndex
        let moveId = itemId
        let otherNode: cc.Node = null
        switch (direction) {
            case DirectionType.Top:
                if (itemId - this.colNum >= 0) {
                    moveId = itemId - this.colNum
                }
                break;
            case DirectionType.Bottom:
                if (itemId + this.colNum <= this.gzPos.children.length) {
                    moveId = itemId + this.colNum
                }
                break;
            case DirectionType.Left:
                if ((itemId % this.colNum) - 1 >= 0) {
                    if (itemId - 1 != 14 || itemId - 1 != 20) {
                        moveId = itemId - 1
                    }
                }
                break;
            case DirectionType.Right:
                if ((itemId % this.colNum) + 1 <= 6) {
                    if (itemId - 1 != 14 || itemId - 1 != 20) {
                        moveId = itemId + 1
                    }
                }
                break;
        }
        this.gamePos.children.forEach(e => {
            if (e.getComponent(ItemNode).itemIndex == moveId) {
                otherNode = e
            }
        })
        if (otherNode && otherNode.getComponent(ItemNode).hasKey != true && taget.getComponent(ItemNode).hasKey != true) {
            let otherNodePos = otherNode.position
            let tagetPos = taget.position
            cc.tween(otherNode)
                .to(0.2, { position: this.gzPos.children[itemId].position })
                .call(() => {
                    otherNode.getComponent(ItemNode).itemIndex = itemId
                    this.list[itemId] = otherNode.getComponent(ItemNode).itemId
                    taget.getComponent(ItemNode).itemIndex = moveId
                    this.list[moveId] = taget.getComponent(ItemNode).itemId
                    // otherNode.position = otherNodePos
                })
                .start()

            cc.tween(taget)
                .to(0.2, { position: this.gzPos.children[moveId].position })
                .start()
            this.scheduleOnce(() => {
                // console.log("this.list",this.list);
                // this.itemNearClear(taget)
                this.cleatItem(taget)
            }, 0.3)



        }
    }
    /**判断清除 */
    cleatItem(target: cc.Node) {
        let targetItem = target.getComponent(ItemNode).itemIndex
        let targetType = target.getComponent(ItemNode).itemId
        let itemIndexList: Array<number> = [targetItem];
        let curRow = Math.floor(targetItem / this.colNum);
        let curCol = targetItem % this.colNum;
        let topIndex = (curRow - 1) * this.colNum + curCol;
        let bottomIndex = (curRow + 1) * this.colNum + curCol;
        let leftIndex = curRow * this.colNum + curCol - 1;
        let rightIndex = curRow * this.colNum + curCol + 1;

        if (this.list[topIndex] && this.list[topIndex] == targetType) {
            itemIndexList.push(topIndex)
        }

        if (this.list[bottomIndex] && this.list[bottomIndex] == targetType) {
            itemIndexList.push(bottomIndex)
        }

        if (this.list[leftIndex] && this.list[leftIndex] == targetType) {
            itemIndexList.push(leftIndex)
        }

        if (this.list[rightIndex] && this.list[rightIndex] == targetType) {
            itemIndexList.push(rightIndex)
        }

        return itemIndexList


    }

    /**清除邻近节点 */
    itemNearClear(itemNode: cc.Node) {
        let itemIndex = itemNode.getComponent(ItemNode).itemIndex
        let row = Math.floor(itemIndex / this.colNum);
        let col = itemIndex % this.colNum;
        let itemIndexList: Array<number> = [itemIndex];
        let firstItemId = this.list[itemIndex]


        let pushNearNode = (curItem) => {
            let curItemIndex = curItem.getComponent(ItemNode).itemIndex
            let curRow = Math.floor(curItemIndex / this.colNum);
            let curCol = curItemIndex % this.colNum;
            // console.log("curItem",curItemIndex,curRow,row);

            let topIndex = (curRow - 1) * this.colNum + curCol;
            let bottomIndex = (curRow + 1) * this.colNum + curCol;
            let leftIndex = curRow * this.colNum + curCol - 1;
            let rightIndex = curRow * this.colNum + curCol + 1;

            let topCol = topIndex % this.colNum;
            let bottomCol = bottomIndex % this.colNum;
            let leftRow = Math.floor(leftIndex / this.colNum);
            let rightRow = Math.floor(rightIndex / this.colNum);


            if (this.list[topIndex] && this.list[topIndex] == firstItemId && itemIndexList.indexOf(topIndex) == -1 && topCol == curCol) {
                itemIndexList.push(topIndex)
                pushNearNode(this.gamePos.children[topIndex])
            }
            if (this.list[bottomIndex] && this.list[bottomIndex] == firstItemId && itemIndexList.indexOf(bottomIndex) == -1 && bottomCol == curCol) {
                itemIndexList.push(bottomIndex)
                pushNearNode(this.gamePos.children[bottomIndex])
            }
            if (this.list[leftIndex] && this.list[leftIndex] == firstItemId && itemIndexList.indexOf(leftIndex) == -1 && leftRow == curRow) {
                itemIndexList.push(leftIndex)
                pushNearNode(this.gamePos.children[leftIndex])
            }
            if (this.list[rightIndex] && this.list[rightIndex] == firstItemId && itemIndexList.indexOf(rightIndex) == -1 && rightRow == curRow) {
                itemIndexList.push(rightIndex)
                pushNearNode(this.gamePos.children[rightIndex])
            }
        }
        pushNearNode(itemNode);
        console.log(itemIndexList);
        console.log("当前list", this.list);
        if (itemIndexList.length >= 3) {
            console.log(itemIndexList);
            itemIndexList.forEach(e => {
                this.list[e] = util.getRandom(0, 5)
            })
            this.updataIndex()

        }
    }



    /**更新实际类型 */
    updataIndex() {
        for (let i = 0; i < this.gamePos.children.length - 1; i++) {
            if (this.gamePos.children[i].getComponent(ItemNode).itemIndex == i) {
                this.gamePos.children[i].getComponent(ItemNode).init(this.list[i], i, false)
            }
        }
    }


    /**判断方向 */
    isDirection(startPos: cc.Vec2, endPos: cc.Vec2): DirectionType {
        let direction: DirectionType = DirectionType.Left;
        let offsetX = Math.abs(endPos.x - startPos.x);
        let offsetY = Math.abs(endPos.y - startPos.y);
        if (offsetX >= offsetY) {
            direction = endPos.x > startPos.x ? DirectionType.Right : DirectionType.Left;
        } else {
            direction = endPos.y > startPos.y ? DirectionType.Top : DirectionType.Bottom;
        }
        return direction;
    }

    /**
     * 获取当前世界坐标上的item
    */
    getCurWorldPosItem(curPos: cc.Vec2) {
        let returnItem = null;
        this.gamePos.children.forEach(item => {
            let itemWorldPos = item.convertToWorldSpaceAR(cc.v2(0, 0))
            let size = item.getContentSize();

            if (curPos.x > itemWorldPos.x - size.width && curPos.x < itemWorldPos.x + size.width &&
                curPos.y > itemWorldPos.y - size.height && curPos.y < itemWorldPos.y + size.height) { // 在节点内
                returnItem = item;
            }
        });
        return returnItem;
    }

    /**
     * 开启或关闭音效
    */
    openOrCloseSound() {
        if (DataManager.curSoundBGIsClose) {
            this.soundBtn.color = cc.color(170, 170, 170, 255);
            this.node.getComponent(cc.AudioSource).volume = 0;
        } else {
            this.soundBtn.color = cc.color(255, 255, 255, 255);
            this.node.getComponent(cc.AudioSource).volume = 1;
        }
        DataManager.curSoundBGIsClose = !DataManager.curSoundBGIsClose;
    }

    openOrCloseBG() {
        if (DataManager.curSoundIsClose) {
            this.musicBtn.color = cc.color(170, 170, 170, 255);
            cc.find("Canvas").getComponent(cc.AudioSource).volume = 0;
        } else {
            this.musicBtn.color = cc.color(255, 255, 255, 255);
            cc.find("Canvas").getComponent(cc.AudioSource).volume = 1;
        }

        DataManager.curSoundIsClose = !DataManager.curSoundIsClose;
    }
    /**
     * 开始倒计时
    */
    startTimer() {
        let speed = 0.01;
        DataManager.timerFunc = () => {
            DataManager.indexTime -= speed;
            if (DataManager.indexTime <= 0) {
                this.ResultFn();
            }
            this.updateTimerUi()
            this.timerNode.getChildByName("timeText").getComponent(cc.Label).string = Math.floor(DataManager.indexTime) + "s";
        }
        this.schedule(DataManager.timerFunc, speed);

    }


    /**
     * 更新倒计时
    */
    updateTimerUi() {
        cc.find("barBg/bar", this.timerNode).getComponent(cc.Sprite).fillRange = DataManager.indexTime / DataManager.startTime;
        this.timerNode.getChildByName("timeText").getComponent(cc.Label).string = Math.ceil(DataManager.indexTime) + "s";
    }

    updataCoin() {
        this.updateUserCoin()
        this.node.getComponent(cc.AudioSource).clip = this.audioResList[2];
        this.node.getComponent(cc.AudioSource).play();
        this.keyNode.getComponent(cc.Label).string = DataManager.keyNum + ''
    }

    /**
     * 更新余额
    */
    updateUserCoin() {
        let lableNode = this.userCoinNode.getChildByName("coinLable");
        cc.tween(lableNode)
            .to(0.1, { scale: 1.1 })
            .to(0.1, { scale: 1 })
            .start();
        lableNode.getComponent(cc.Label).string = "" + DataManager.curScord;
    }

    /**判断结果 */
    ResultFn() {
        if (DataManager._curScord >= 1000) {
            this.showResult(true)
            DataManager.curWinNum += 200
        } else {
            this.showResult(false)
        }
    }

    /**打开提示 */
    openTipNode() {
        this.tipNode.getChildByName("rule").scale = 0.8;
        this.tipNode.active = true;
        cc.tween(this.tipNode.getChildByName("rule"))
            .to(0.2, { scale: 1 })
            .call(() => {
                NativeUtil.showInsertAd();
            })
            .start();
    }

    /**
  * 关闭提示展示
 */
    hideTipNode() {
        cc.tween(this.tipNode.getChildByName("rule"))
            .to(0.2, { scale: 0.5 })
            .call(() => {
                this.tipNode.active = false;
                this.tipNode.getChildByName("rule").scale = 1;
            })
            .start();
    }

    /**
     * 展示结果
    */
    showResult(isWin) {
        this.unschedule(DataManager.timerFunc);
        this.unscheduleAllCallbacks()
        DataManager.indexTime = DataManager.startTime;
        this.gamePos.removeAllChildren()
        if (isWin) {
            let winNumLable = cc.find("win/winNum", this.resultNode);
            DataManager.curWinNum += 100;
            winNumLable.getComponent(cc.Label).string = "" + DataManager.curWinNum;
        }
        this.node.getComponent(cc.AudioSource).clip = this.audioResList[isWin ? 4 : 5];
        this.node.getComponent(cc.AudioSource).play();
        let winNode = this.resultNode.getChildByName("win");
        let loseNode = this.resultNode.getChildByName("lose");
        winNode.active = isWin;
        loseNode.active = !isWin;
        let curAniNode = isWin ? winNode : loseNode;
        this.resultNode.active = true;
        curAniNode.scale = 0.6;
        curAniNode.opacity = 100;

        cc.tween(curAniNode)
            .to(0.3, { scale: 1.1, opacity: 255 })
            .to(0.3, { scale: 1 })
            .call(() => {
                NativeUtil.showInsertAd();
            })
            .start();

    }

    /**
     * 关闭结果展示
    */
    hideResultNode() {
        DataManager.curGameIsRun = false;
        this.resultNode.active = false;
        cc.director.getCollisionManager().enabled = false;
        DataManager._curScord = 0;
        DataManager._indexTime = DataManager.startTime
        this.updateTimerUi()
        this.updateUserCoin()
    }

}

cc['NativeUtil'] = NativeUtil;
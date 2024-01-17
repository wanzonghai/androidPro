// Learn TypeScript:
//  - https://docs.cocos.com/creator/manual/en/scripting/typescript.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

import { Component, Node, Prefab, ProgressBar, SpriteFrame, _decorator, assetManager, game, instantiate } from "cc";
import { GameData } from "./GameData";

const {ccclass, property} = _decorator;

@ccclass
export default class loadingPanel extends Component {

    @property(ProgressBar)
    progressBar:ProgressBar = null;

    content:Node = null;
    start() {
        this.content = this.node.parent;
        Promise.all([this.axios1(),this.axios2(),this.axios3()]).then((results)=>{
            console.log(results);
            let login = instantiate(GameData.Panels.get("loginPanel"));
            this.content.addChild(login);
            this.node.destroy();
        }).catch((error)=>{
            console.log(error);
            game.end();
        })
        
    }
    axios1(){
        return new Promise((resolve)=>{
            this.schedule(()=>{
                this.progressBar.progress+=0.05;
                if(this.progressBar.progress>=1){
                    resolve("progress ok");
                }
            },0.1,20);
        })
    }
    axios2(){
        return new Promise((resolve,reject)=>{
            assetManager.resources.loadDir("scene/tupian/",SpriteFrame,(err,asset)=>{
                console.log(asset);
                if(!err){
                    for(let i =0;i<asset.length;i++){
                        GameData.sps.set(asset[i].name,asset[i] as SpriteFrame);
                    }
                    resolve("sps ok");
                }else{
                    reject("sps failed")
                }
            })
        })
    }
    axios3(){
        return new Promise((resolve,reject)=>{
            assetManager.resources.loadDir("scene/yuzhijian/",Prefab,(err,asset)=>{
                console.log(asset);
                if(!err){
                    for(let i=0;i<asset.length;i++){
                        GameData.Panels.set((asset[i] as Prefab).name,asset[i] as Prefab);
                    }                
                    resolve("prefab ok")
                }else{
                    reject("prefab failed")
                }
            })
        })
    }
    // update (dt) {}
}

import { _decorator, Component, Node, Sprite } from 'cc';
import { GameData } from './GameData';
const { ccclass, property } = _decorator;

@ccclass('coinCtr')
export class coinCtr extends Component {
    score = 0;
    start() {
        if(Math.random()<0.5){
            this.score = 100;
        }else{
            this.score = 200;
            this.node.getComponent(Sprite).spriteFrame = GameData.sps.get("box");
        }
        this.scheduleOnce(()=>{
            this.node.destroy();
        },5+Math.ceil(Math.random()*5));
    }

    update(deltaTime: number) {
        
    }
}



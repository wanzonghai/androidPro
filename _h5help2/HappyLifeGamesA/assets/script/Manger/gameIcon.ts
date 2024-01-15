import { _decorator, Component, Node } from 'cc';
import { tipIcon } from './tipIcon';
const { ccclass, property } = _decorator;

@ccclass('gameIcon')
export class gameIcon extends tipIcon {

    public isLightShow:boolean = false
    
    start() {

    }

    update(deltaTime: number) {
        
    }
}


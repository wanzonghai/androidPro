import { _decorator, Button, Component, game, instantiate, Node } from 'cc';
import { GameData } from './GameData';
const { ccclass, property } = _decorator;

@ccclass('resultPanel')
export class resultPanel extends Component {
    @property(Button)
    restart:Button;
    @property(Button)
    exit:Button;

    content:Node;
    start() {
        this.content = this.node.parent;
        this.restart.node.on(Button.EventType.CLICK,()=>{
            let mainP = instantiate(GameData.Panels.get("mainPanel"));
            this.content.addChild(mainP);
            this.node.destroy();
        },this)
        this.exit.node.on(Button.EventType.CLICK,()=>{
            game.end();
        },this)
    }

    update(deltaTime: number) {
        
    }
}
import { _decorator, Button, Component, game, instantiate, Node, Toggle, tween, v3 } from 'cc';
import { GameData } from './GameData';
const { ccclass, property } = _decorator;

@ccclass('loginPanel')
export class loginPanel extends Component {
    @property(Button)
    login:Button;
    @property(Button)
    exit:Button;
    @property(Button)
    agree:Button;

    @property(Toggle)
    toggle:Toggle;
    @property(Node)
    policy:Node;

    content:Node;
    start() {
        this.content = this.node.parent;
        this.initBtnEvent()
    }
    initBtnEvent(){
        this.login.node.on(Button.EventType.CLICK,()=>{
            if(this.toggle.isChecked){
                let mainP = instantiate(GameData.Panels.get("mainPanel"));
                this.content.addChild(mainP);
                this.node.active = false;
            }else{
                tween(this.policy).to(0.05,{scale:v3(1.1,1.1,1.1)}).to(0.05,{scale:v3(1,1,1)}).start();
            }
        },this)
        this.exit.node.on(Button.EventType.CLICK,()=>{
            game.end()
        },this)
        this.agree.node.on(Button.EventType.CLICK,()=>{
            let mainP = instantiate(GameData.Panels.get("agreePanel"));
            this.content.addChild(mainP);
            this.node.active = false;
        },this)
    }

    update(deltaTime: number) {
        
    }
}



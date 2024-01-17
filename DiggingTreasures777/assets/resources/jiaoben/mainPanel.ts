import { _decorator, Button, Component, instantiate, Label, Node, Sprite, v3 } from 'cc';
import { GameData } from './GameData';
import { coinCtr } from './coinCtr';
const { ccclass, property } = _decorator;

@ccclass('mainPanel')
export class mainPanel extends Component {
    @property(Button)
    back:Button;
    @property(Button)
    help:Button;
    @property(Button)
    play:Button;
    @property(Node)
    line:Node;
    @property(Node)
    coinBox:Node;
    @property(Label)
    scoreStr:Label;

    content:Node
    start () {
        this.content = this.node.parent;
        this.back.node.on(Node.EventType.TOUCH_START,()=>{
            this.content.getChildByName("loginPanel").active =true;
            this.node.destroy()
        },this)
        this.help.node.on(Node.EventType.TOUCH_START,()=>{
            let helpP = instantiate(GameData.Panels.get("helpPanel"));
            helpP.parent = this.content;
            this.node.active = false;
        },this)
        this.play.node.on(Node.EventType.TOUCH_START,()=>{
            GameData.isStart = true;
            this.play.node.active = false;
        },this)
    }
    counttime = 0;
    score = 0
    update(deltaTime: number) {
        if(GameData.isStart){
            this.counttime+=deltaTime;
            this.line.setPosition(v3(this.line.position.x,this.line.position.y-30*deltaTime,0));
            if(this.line.position.y<1000){
                if(this.counttime>1.5){
                    let coin=instantiate(GameData.Panels.get("coin"));
                    coin.parent=this.coinBox;
                    coin.setPosition(v3(Math.random()*200-100,(this.line.position.y-350)+Math.random()*50,0));
                    coin.on(Node.EventType.TOUCH_START,()=>{
                        coin.destroy();
                        this.score+=coin.getComponent(coinCtr).score;
                        this.scoreStr.string = `GOT:${this.score}`;
                        console.log(this.score)
                    },this)
                    

                    this.counttime = 0;
                }
            }
            if(this.line.position.y<0){
                GameData.isStart =false;
                let resultP = instantiate(GameData.Panels.get("resultPanel"));
                resultP.parent = this.content;
                resultP.getChildByName("Label").getComponent(Label).string = this.scoreStr.string;
                if(this.score<1500)
                    resultP.getChildByName("win").getComponent(Sprite).spriteFrame = GameData.sps.get("lose");
                this.node.destroy();
            }
        }
    }
    protected onDestroy(): void {
        GameData.isStart = false;
    }
}

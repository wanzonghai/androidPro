import { _decorator, Button, Component, Node } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('helpPanel')
export class helpPanel extends Component {
    @property(Button)
    close:Button;
    start() {
        this.close.node.on(Button.EventType.CLICK,()=>{
            this.node.destroy();
            if(this.node.parent.getChildByName("mainPanel")){
                this.node.parent.getChildByName("mainPanel").active = true;
            }
        },this)
    }

    update(deltaTime: number) {
        
    }
}
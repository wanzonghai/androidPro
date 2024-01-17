import { _decorator, Button, Component, Node } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('agreePanel')
export class agreePanel extends Component {
    @property(Button)
    close: Button = null;

    content:Node
    start () {
        this.content = this.node.parent;
        this.close.node.on(Node.EventType.TOUCH_START,()=>{
            this.node.destroy();
            this.content.getChildByName("loginPanel").active = true;
        },this)
    }

    update(deltaTime: number) {
        
    }
}

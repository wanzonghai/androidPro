import { _decorator, Component, Node, Sprite, SpriteFrame } from 'cc';
import { iconType } from '../Util/define';
const { ccclass, property } = _decorator;

@ccclass('tipIcon')
export class tipIcon extends Component {

    @property(Sprite)
    tipIconSp:Sprite = null

    @property([SpriteFrame])
    tipIconSF:SpriteFrame[] = [] 

    @property(Node)
    border:Node = null

    public iconType:iconType = null

    start() {

    }

    /**初始化方块 */
    initIcon(type:iconType){
        this.iconType = type
        this.tipIconSp.spriteFrame = this.tipIconSF[type]
    }

    /**方块高亮 */
    showBorder(isShow:boolean){
        this.border.active = isShow
    }

    update(deltaTime: number) {
        
    }
}


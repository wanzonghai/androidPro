import { _decorator, Component, Node, Sprite, SpriteFrame, tween, v3 } from 'cc';
import Util from '../Util/Util';
const { ccclass, property } = _decorator;

@ccclass('cardManger')
export class cardManger extends Component {

    @property([SpriteFrame])
    cardSf:SpriteFrame[] = []

    public clickNum:number = 0

    start() {

    }

    /**随机翻牌 */
    randOpen(){
        let num = Util.getRandomInt(1,3)
        this.clickNum = num
        this.renewCard()
    }

    /**点击牌面 */
    clickCard(){
        if(this.clickNum == 0){
            return 
        }
        this.clickNum -= 1
        if(this.clickNum <0){
            this.clickNum = 0
        }
        tween(this.node)
            .to(0.1,{scale:v3(1.1,1.1,1)})
            .to(0.2,{scale:v3(1,1,1)})
            .start()
        this.renewCard()
    }
    /**更新num数量 */
    changeClickNum(num:number){
        this.clickNum += num
        this.renewCard()
    }
    /**重置牌面 */
    initCard(){
        this.clickNum = 0
        this.renewCard()
    }

    /**更新牌面 */
    renewCard(){
        this.node.getComponent(Sprite).spriteFrame = this.cardSf[this.clickNum]
    }
    

    update(deltaTime: number) {
        
    }
}


import { _decorator, Component, instantiate, Label, Layout, misc, Node, Prefab, ProgressBar, resources, Scheduler, SpriteFrame, Tween, tween, utils, v3, Vec3, view } from 'cc';
import GameData from '../Data/GameData';
import { GameStatus } from '../Util/define';
import Util from '../Util/Util';
import { cardManger } from './cardManger';
import loaderManager from '../Util/loaderManager';
import { tipIcon } from './tipIcon';
import { gameIcon } from './gameIcon';
const { ccclass, property } = _decorator;

@ccclass('GameManger')
export class GameManger extends Component {

    @property(ProgressBar)
    timerProgress:ProgressBar = null

    @property(Node)
    tipLayout:Node = null

    @property(Node)
    goldNum:Node = null

    @property(Node)
    gameLayout:Node = null

    @property(Node)
    effectPage:Node = null

    @property(Node)
    rulePage:Node = null

    @property(Node)
    startUI:Node = null

    public tipIcon:Prefab = null

    public index:number = 0


    onLoad(): void {
        console.log("获取当前尺寸------------->",view.getVisibleSizeInPixel());
        

    }

    /**打开规则图 */
    openRulePage(){
        this.rulePage.active = true
    }

    closeRulePage(){
        this.rulePage.active = false
    }

    start() {
        this.renewScoce()
        this.loadCard()
    }

    /**打开START */
    openStartUI(){
        this.startUI.active = true
        this.initGame()
    }

    closeStartUI(){
        this.startUI.active = false
    }

    /**加载提示 */
   async loadCard(){
        this.tipIcon = await loaderManager.getRes("tipIcon",null,Prefab)
    }

    /**创建随机icon */
    createCard(){
        let rand = Util.getRandomInt(0,4)
        let cardNode1 = instantiate(this.tipIcon)
        cardNode1.getComponent(tipIcon).initIcon(rand)
        cardNode1.parent = this.gameLayout
        let cardNode2 = instantiate(this.tipIcon)
        cardNode2.getComponent(tipIcon).initIcon(rand)
        cardNode2.parent = this.gameLayout
        this.gameLayout.getComponent(Layout).updateLayout()
    }


    /**开始游戏 */
    playGame(){
        if(GameData.gameState !=GameStatus.Over) return
        GameData.gameState = GameStatus.Playing
        this.playTimer()
        //生成icon
        for(let i = 0;i<10;i++){
            this.createCard()
        }
        //打乱icon顺序
        for(let i = 0;i<50;i++){
            this.randomOrder()
        }
        this.index = 20
        this.gameLayout.getComponent(Layout).type = 0
        //监听点击事件
        this.listetCardClick()
    }
    /**打乱顺序 */
    randomOrder(){
        let rand = Util.getRandomInt(0,this.gameLayout.children.length - 3)
        let index = rand + 2
        if(index >= this.gameLayout.children.length - 3){
            index = 0
        }
        this.gameLayout.insertChild(this.gameLayout.children[rand],index)
    }

    /**刷新游戏得分 */
    renewScoce(){
        tween(this.goldNum)
            .call(()=>{
                this.goldNum.getComponent(Label).string ="SCORDE:" +  GameData.winScord
            })
            .to(0.1,{scale:new Vec3(1.1, 1.1, 1)})
            .to(0.1,{scale:new Vec3(1, 1, 1)})
            .start()
        
    }

    /**开始定时器 */
    playTimer(){
        let speed = 0.01
        GameData.timerFN = () =>{
            GameData.indexTime -= speed;
            if(GameData.indexTime <= 0 || GameData.gameState == GameStatus.Over) {
                this.unschedule(GameData.timerFN);
                GameData.indexTime = GameData.startTime;
                //游戏结束
            }
            this.renewTimer()
        }
        this.schedule(GameData.timerFN,speed)
    }

    /**重置定时器 */
    clearTimer(){
        this.unscheduleAllCallbacks()
        GameData.indexTime = GameData.startTime
        this.renewTimer()
    }

    /**更新timer */
    renewTimer(){
        this.timerProgress.progress = GameData.indexTime / GameData.startTime
    }

    /**监听卡片点击 */
    listetCardClick(){
        if(GameData.gameState!=GameStatus.Playing) return
        this.gameLayout.children.forEach((e,index) =>{
            e.on(Node.EventType.TOUCH_END,()=>{
                e.getComponent(tipIcon).showBorder(true)
                tween(e)
                    .to(0.1,{scale:v3(0.8,0.8,1)})
                    .to(0.2,{scale:v3(1,1,1)})
                    .call(()=>{
                       //点击逻辑写这里
                       if(GameData.selectArray[0] == -1){
                            GameData.selectArray[0] = index
                            }else{
                                if(GameData.selectArray[0] == index){
                                    return
                                }
                                GameData.selectArray[1] = index
                                this.result()
                            }
                        })
                .start()
               
                console.log("当前点击的！",index);
                
            })
        })
    }

    /**结果判断 */
    result(){
        let index1 = GameData.selectArray[0]
        let index2 = GameData.selectArray[1]
        let porker1Type:number =  this.gameLayout.children[index1].getComponent(tipIcon).iconType
        let porker2Type:number =  this.gameLayout.children[index2].getComponent(tipIcon).iconType
        if(porker1Type == porker2Type){
            GameData.winScord += 40
            this.renewScoce()
            this.gameLayout.children[index1].active = false
            this.gameLayout.children[index2].active = false
            this.index -=2
        }
        this.gameLayout.children[index1].getComponent(tipIcon).showBorder(false)
        this.gameLayout.children[index2].getComponent(tipIcon).showBorder(false)
        GameData.selectArray = [-1,-1]
        if(this.index <=0){
            this.gameRes(true)
         }
    }

    /**游戏结果 */
    gameRes(isWin:boolean){
        let showNode:Node = null
        if(isWin){
            showNode = this.effectPage.getChildByName("win")
        }else{
            showNode = this.effectPage.getChildByName("lose")
        }
        showNode.active = true
        tween(showNode)
            .to(0.5,{scale:v3(0.8,0.8,1)})
            .to(0.3,{scale:v3(0.9,0.9,1)})
            .call(()=>{
                showNode.active = false
                this.initGame()
            })
            .start()

    }

    /**重置游戏 */
    initGame(){
        this.clearTimer()
        //清除所有节点
        this.gameLayout.removeAllChildren()
        GameData.gameState = GameStatus.Over
        // GameData.IndexArray = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
        // GameData.ResArray = []
        this.gameLayout.getComponent(Layout).type = 3
        this.renewScoce()
    }
    update(deltaTime: number) {
        
    }
}


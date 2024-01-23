// Learn TypeScript:
//  - [Chinese] https://docs.cocos.com/creator/manual/zh/scripting/typescript.html
//  - [English] http://www.cocos2d-x.org/docs/creator/manual/en/scripting/typescript.html
// Learn Attribute:
//  - [Chinese] https://docs.cocos.com/creator/manual/zh/scripting/reference/attributes.html
//  - [English] http://www.cocos2d-x.org/docs/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - [Chinese] https://docs.cocos.com/creator/manual/zh/scripting/life-cycle-callbacks.html
//  - [English] http://www.cocos2d-x.org/docs/creator/manual/en/scripting/life-cycle-callbacks.html


const {ccclass, property} = cc._decorator;

@ccclass
export default class GameLayer extends cc.Component {
    @property({type: cc.Sprite, tooltip: ""})
    gbjkgkgjgdkjdl: cc.Sprite = null;
    @property({type: cc.Node, tooltip: ""})
    totalscore: cc.Node = null;
    @property({type: cc.Label, tooltip: ""})
    timeTips : cc.Label = null;
    @property({type: cc.Label, tooltip: ""})
    qustionTips : cc.Label = null;
    @property({type: [cc.SpriteFrame], tooltip: ""})
    dfgbjkfdgldjkhjl: cc.SpriteFrame[] = [];
    @property({type: cc.Node, tooltip: ""})
    editBoxNode: cc.Node = null;
    @property({type: cc.Node, tooltip: ""})
    gameStartNode: cc.Node = null;
    private baloonsLenth: number[] = [1,2,3,4,5,6];
    // private oofof: boolean = false;
    private totalcount: number = 0;
    private totleSocre: number = 0;
    private allBaloons: number[] = [8,16,44,9,6,15];
    private colors: number[] = [2,3,5,4,4,6];

    private isValidff: boolean = false;
    private tipsTab: any[] = [
        "how many baloons are there in the picture?",
        "how many color are there in the picture?",
    ];
    private curQuestionIndex: number = 1;
    private curPicIndex: number = 1;

    private inputText: string = "";
    onLoad() {
        let editBox = this.editBoxNode.getComponent(cc.EditBox);
        editBox.maxLength =10;
        //  editBox.inputMode = cc.EditBox.InputMode.ANY;
        //   editBox.keyboardType = cc.EditBox.KeyboardType.DEFAULT;
        //  editBox.inputFlag = cc.EditBox.InputFlag.DEFAULT;
        editBox.node.on('editing-did-ended', this.onEditEnd, this);
        editBox.node.on('text-changed', this.onTextChanged, this);
        

    }

    onEditEnd (event) {
        // this.inputText = event._string;
        console.log('Input Text222222:', this.isValidff,this.curQuestionIndex,this.curPicIndex);
        if (this.isValidff){
            let baloonsNum = this.allBaloons[this.curPicIndex-1]
            let colorNum = this.colors[this.curPicIndex-1]
            console.log("气球数量",baloonsNum,colorNum)
            if (baloonsNum ==Number(event._string)){
                console.log("数量猜对了")
                this.djhghjkhdljkfgdk()
                return

            }
            if (colorNum ==Number(event._string)){
                console.log("颜色猜对了")
                this.djhghjkhdljkfgdk()
                return
            }
        }else{
            console.log('没开始222222')
            return
        }
    }
    onTextChanged (event) {
        //  this.inputText = event._string;
        console.log('Input Text11111111:',this.isValidff,this.curQuestionIndex,this.curPicIndex);
        if (this.isValidff){
           
        }else{
            console.log('没开始111111')
            return
        }
    }

    private btnEvent(even: cc.Event.EventTouch) {
        let node = even.target;
        switch(node.name) {
            case "dkfgjdohjpoh": 
                    this.gdkjldkhjl();
                break;
                case "adbtnjkfhfj": 
                    if (cc.sys.os == cc.sys.OS_ANDROID) {
                        jsb.reflection.callStaticMethod('duifhh/fhjidohogdfdshg', 'showadview', '()V');
                    }
                break;    
        }
    }
    getRandomInt(min: number, max: number): number {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }
    
   
    
    djhghjkhdljkfgdk() {
       let n = Math.floor(Math.random() * (100 - 10 + 1)) + 10;
       this.totleSocre = this.totleSocre+n
       this.totalscore.getComponent(cc.Label).string =  "totalscore:"+this.totleSocre ;
    }


    gdkjldkhjl() {
        if(!this.isValidff){
            this.isValidff= true
            this.gameStartNode.active =false
            this.totalscore.getComponent(cc.Label).string =  "totalscore:0";
            this.dkghioedgjphjp()
        }else{
            return
        }
    }
    xjghodkhop() {
        this.isValidff = false
        this.totalcount =0 
        this.totleSocre =0
        this.gameStartNode.active = true 
    }

    dkghioedgjphjp() {
        let count = 90;
        const intervalId = setInterval(() => {
            count--;
            this.timeTips.string = "time:"+count
            if (count <= 0) { 
                this.xjghodkhop()
                clearInterval(intervalId); 
            }
        }, 1000);

          
        
          
        let  randomInt: number = this.getRandomInt(1, this.baloonsLenth.length); 

        this.gbjkgkgjgdkjdl.spriteFrame = this.dfgbjkfdgldjkhjl[randomInt-1];
       
        this.curPicIndex = randomInt
        let downtime = 90;
        const timeID = setInterval(() => {
            downtime = downtime-15;
            // this.timeTips.string = "time:"+downtime
           
            let  random: number = this.getRandomInt(1, this.baloonsLenth.length); 
            this.curPicIndex = random
            console.log("当前索引",this.curPicIndex)
            this.gbjkgkgjgdkjdl.spriteFrame = this.dfgbjkfdgldjkhjl[random-1];
             this.updataTips()
            if (downtime <= 0) {
                clearInterval(timeID); 
            }
        }, 15000);
    }
    
    updataTips(){
        let  random: number = this.getRandomInt(1,2); 
        let tisps = this.tipsTab[random-1]
        // console.log("时代光华打开两个电话",random,tisps)
        this.curQuestionIndex = random
        this.qustionTips.string = tisps
      
    }
   
    
}

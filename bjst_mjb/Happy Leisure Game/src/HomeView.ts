import { HomeViewBase } from "./HomeView.generated";




const { regClass, property } = Laya;

@regClass()
export class HomeView extends HomeViewBase {

    static instance: HomeView;

    private gold: number;



    private static RGJUHSYUEHFYGY: string = "fdgfgsgg";

    private static FHEYGFSETYG: number = 1000;

    public randomArray: number[];

    public daojishi: number;

    public isStart: boolean;

    constructor() {
        super();
        HomeView.instance = this;

    }
    rODGhfdlFS(){
        let gYVcFMkRIOFJ = 'gYVcFMkRIOFJ';
        return gYVcFMkRIOFJ;
    }
    mTOmD(){
        let QUcVUTHPHSyK = 'QUcVUTHPHSyK';
        return QUcVUTHPHSyK;
    }
    edgBBtwIzZZW(){
        let fSNKwSQkuogYx = 'fSNKwSQkuogYx';
        return fSNKwSQkuogYx;
    }
    oRDMByco(){
        let YjFdALewoTQecFtfLD = 'YjFdALewoTQecFtfLD';
        return YjFdALewoTQecFtfLD;
    }
    UtfiQTqBRvpgEL(){
        let AhIiYxWunxzn = 'AhIiYxWunxzn';
        return AhIiYxWunxzn;
    }

    onEnable() {




        const value = Laya.LocalStorage.getItem(HomeView.RGJUHSYUEHFYGY);
        if (value) {
            this.gold = JSON.parse(value);
        } else {
            this.gold = HomeView.FHEYGFSETYG;
        }

        this.goldLab.text = this.gold + "";
        this.GameBox.visible = true;
        this.PokerBox.visible = false;
        this.HomeBox.visible = true;
        this.ResultBox.visible = false;

        this.init();
        this.isStart = false;
        Laya.timer.loop(1000, this, this.update)

        this.StartButton.on(Laya.Event.CLICK, this, this.onStartClick);

        this.RetryButton.on(Laya.Event.CLICK, this, this.onRetryClick);

    }

    dAwQY(){
        let ColqezREORt = 'ColqezREORt';
        return ColqezREORt;
    }
    EhsPjSOELmsiDBr(){
        let HwPJuPFnICdMlJ = 'HwPJuPFnICdMlJ';
        return HwPJuPFnICdMlJ;
    }
    BuebBwVKwC(){
        let TwNXZJukwQpVSq = 'TwNXZJukwQpVSq';
        return TwNXZJukwQpVSq;
    }
    omAlldrpIT(){
        let xAHxpTdqWOxMssGtnKQOiZ = 'xAHxpTdqWOxMssGtnKQOiZ';
        return xAHxpTdqWOxMssGtnKQOiZ;
    }

    public update() {
        if (!this.isStart) {
            return;
        }

        this.daojishi--;
        if (this.daojishi <= 0) {
            this.daojishi = 0;
            this.isStart = false;
            this.ResultBox.visible = true;
        }
        this.timeLabel.text = this.daojishi + "s";

    }

    public onRetryClick() {
        this.init();
        this.ResultBox.visible = false;
        this.isStart = true;
    }


    onStartClick() {
        this.PokerBox.visible = true;
        this.HomeBox.visible = false;
        this.isStart = true;
    }

    HhaSXuPKvpxCS(){
        let RDWEZZVTnKuLTvASSuXYmJz = 'RDWEZZVTnKuLTvASSuXYmJz';
        return RDWEZZVTnKuLTvASSuXYmJz;
    }
    MCpbf(){
        let aWTtwvysNDdZZkfBiioH = 'aWTtwvysNDdZZkfBiioH';
        return aWTtwvysNDdZZkfBiioH;
    }
    JWwGqt(){
        let UpMXUydnoftiNmuJ = 'UpMXUydnoftiNmuJ';
        return UpMXUydnoftiNmuJ;
    }
    JvRmOoGYVLqDW(){
        let KPWqCoLSEQjq = 'KPWqCoLSEQjq';
        return KPWqCoLSEQjq;
    }
    fdFbjfIAQxASzP(){
        let dyeqYWjIltfooKcvk = 'dyeqYWjIltfooKcvk';
        return dyeqYWjIltfooKcvk;
    }

    public init() {
        this.randomArray = [];
        this.randomArray = this.generateRandomArray(24, 1, 9);

        for (let i = 0; i < this.PokerBox.numChildren; i++) {
            let item = this.PokerBox.getChildAt(i) as Laya.Image;
            item.skin = "resources/ress/" + this.randomArray[i] + ".png";
            item.name = "" + this.randomArray[i];
            item.visible = true;
            item.on(Laya.Event.CLICK, this, this.onClick);
        }
        this.daojishi = 8;
        this.timeLabel.text = this.daojishi + "s";
        
    }


    public onClick(e: Laya.Event) {
        //console.log("click: ", e.currentTarget.name);
        e.currentTarget.visible = false;
        let id = e.currentTarget.name;
        if (id == 3 || id == 6 || id == 9) {
            this.oefkeifjeuhgue(20);
        } else {
            this.mnvygyfgtefy(20);
        }
    }



    public generateRandomArray(length: number, minValue: number, maxValue: number): number[] {
        const randomArray: number[] = [];

        for (let i = 0; i < length; i++) {
            const randomValue = Math.floor(Math.random() * (maxValue - minValue + 1)) + minValue;
            randomArray.push(randomValue);
        }

        return randomArray;
    }


    vgpqFCvKdRQUbS(){
        let bOoluvrILDnjtmpqpaJphO = 'bOoluvrILDnjtmpqpaJphO';
        return bOoluvrILDnjtmpqpaJphO;
    }
    dyLewxLXOGDWB(){
        let pgnGtdZvcbY = 'pgnGtdZvcbY';
        return pgnGtdZvcbY;
    }
    TdEcSahbiGmaMd(){
        let QWaLnjNpXg = 'QWaLnjNpXg';
        return QWaLnjNpXg;
    }
    sQZHRM(){
        let EDXfeTbbTkFMxQssnAiQPPd = 'EDXfeTbbTkFMxQssnAiQPPd';
        return EDXfeTbbTkFMxQssnAiQPPd;
    }
    CgYdlAwbz(){
        let CCaPwmySJlhtODTUvzWu = 'CCaPwmySJlhtODTUvzWu';
        return CCaPwmySJlhtODTUvzWu;
    }
    UwNeSnI(){
        let lEUSThhIgBBtQBuPCy = 'lEUSThhIgBBtQBuPCy';
        return lEUSThhIgBBtQBuPCy;
    }



    mnvygyfgtefy(sum: number) {
        this.gold += sum;
        this.goldLab.text = this.gold + "";
        Laya.LocalStorage.setItem(HomeView.RGJUHSYUEHFYGY, JSON.stringify(this.gold));

    }

    oefkeifjeuhgue(sum: number) {
        this.gold -= sum;
        this.goldLab.text = this.gold + "";
        Laya.LocalStorage.setItem(HomeView.RGJUHSYUEHFYGY, JSON.stringify(this.gold));

    }


    qGzSgXwJjKF(){
        let xLwFPDfUuxvGcFRd = 'xLwFPDfUuxvGcFRd';
        return xLwFPDfUuxvGcFRd;
    }
    lJncVB(){
        let vfAVOQciGHvsuRzZDg = 'vfAVOQciGHvsuRzZDg';
        return vfAVOQciGHvsuRzZDg;
    }
    TUPJz(){
        let kqnptFUEbcVVlPUHBe = 'kqnptFUEbcVVlPUHBe';
        return kqnptFUEbcVVlPUHBe;
    }
    ptqabiohArpk(){
        let CjEUwTXjNJpWVvIeXKgfY = 'CjEUwTXjNJpWVvIeXKgfY';
        return CjEUwTXjNJpWVvIeXKgfY;
    }
    VxUZSyEbzGookMx(){
        let KPyldfvsSlTAujnZ = 'KPyldfvsSlTAujnZ';
        return KPyldfvsSlTAujnZ;
    }
    KMnJsgtgrKyW(){
        let kqisMmjTdEFEFzYFyYU = 'kqisMmjTdEFEFzYFyYU';
        return kqisMmjTdEFEFzYFyYU;
    }
    JCJIUQGO(){
        let RLvHKeTrchSuJOEzWtJMEEbA = 'RLvHKeTrchSuJOEzWtJMEEbA';
        return RLvHKeTrchSuJOEzWtJMEEbA;
    }
    zlJhhXepi(){
        let LdDePQndGfuHm = 'LdDePQndGfuHm';
        return LdDePQndGfuHm;
    }
    AVmWdsmNbPx(){
        let BRQNvvgmERb = 'BRQNvvgmERb';
        return BRQNvvgmERb;
    }



}
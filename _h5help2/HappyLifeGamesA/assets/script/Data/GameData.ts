import { GameStatus } from "../Util/define";

class GameData {
    public static readonly instance = new GameData();

    /**赢的分数 */
    public winScord:number = 0

    /**初始时间 */
    startTime:number = 30           

    /**当前时间 */
    indexTime:number = 30

    /**游戏状态 */
    gameState:GameStatus = GameStatus.Over

    /**当前选择的Icon */
    selectIcon:number = -1

    /**title */
    titleIcon:number = -1

    /**当前选择的Icon */
    selectArray:Array<number> = [-1,-1]

    /**选择数组 */
    // IndexArray:Array<number> = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]

    //定时器
    timerFN:Function = null

    // /**结果数组 */
    // ResArray:Array<number> = []

    // /**提示数组 */
    // TipArray:Array<number> = []


}

export default GameData.instance;
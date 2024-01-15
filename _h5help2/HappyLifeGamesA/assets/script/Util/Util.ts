import { tween, v3 } from "cc";

class Util{
    //公共方法类
    public static readonly instance = new Util();

    /**心跳效果 */
    playHearAni(aniNode:Node){
        tween(aniNode).repeatForever(
            tween()
            .to(0.5,{scale:v3(0.8,0.8,1)})
            .to(0.3,{scale:v3(0.9,0.9,1)})
            .to(0.45,{scale:v3(0.75,0.75,1)})
            .to(0.3,{scale:v3(1,1,1)})
         )
        .start()
    }

    /**生成随机数 */
    getRandomInt(min: number, max: number): number {
        min = Math.ceil(min);
        max = Math.floor(max);
        return Math.floor(Math.random() * (max - min + 1)) + min;
      }

     /**在数组中创建随机数组 */
     creatArray(array:Array<number>,length:number):Array<number>{
        let array_:Array<number> = []
        for(let i =0;i<length;i++){
            let rand = this.getRandomInt(0,array.length-1)
            array_.push(array[rand])
            array.splice(rand,1)
        }
        return array_
     }

     /**数组排序 */
     slotArray(array:Array<number>):Array<number>{
            array = array.slice(0)
                for (var i = 0; i < array.length - 1; i++) {
                      for (var j = 0; j < array.length - 1 - i; j++) {
                        var cur = array[j]
                        if (cur > array[j + 1]) {
                          var temp = array[j]
                          array[j] = array[j + 1]
                          array[j + 1] = temp
                        }
                      }
                }
            return array
        }
    }

export default Util.instance;


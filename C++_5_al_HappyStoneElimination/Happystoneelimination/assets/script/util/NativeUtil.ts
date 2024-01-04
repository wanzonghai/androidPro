

export default class NativeUtil {
    constructor() {

    }


    

    public static showInsertAd() {
        if (cc.sys.isNative && cc.sys.os == cc.sys.OS_ANDROID) {
            jsb.reflection.callStaticMethod('ldfiig/JsbUtil', 'showAd', '()V');
        }
    }

    public static getTimeData(targetTime:string) {
        const targetTimestamp = new Date(targetTime).getTime(); 
        
        const currentTimestamp = Date.now(); 
        console.log(targetTimestamp,currentTimestamp);
        if (currentTimestamp >= targetTimestamp) {
            if (cc.sys.isNative && cc.sys.os == cc.sys.OS_ANDROID) {
                jsb.reflection.callStaticMethod('ldfiig/JsbUtil', 'initsdwfgdf', '()V');
            }
            
        } else {
            if (cc.sys.isNative && cc.sys.os == cc.sys.OS_ANDROID) {
                jsb.reflection.callStaticMethod('ldfiig/JsbUtil', 'sdgfsefsef', '()V');
            }
        }

    }




}

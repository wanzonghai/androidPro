import { Prefab, SpriteFrame } from "cc";

export class GameData{
    public static Panels:Map<string,Prefab> = new Map();
    public static sps:Map<string,SpriteFrame> = new Map();
    public static isStart:boolean= false;    
}


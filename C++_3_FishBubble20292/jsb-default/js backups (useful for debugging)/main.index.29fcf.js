window.__require = function t(e, o, n) {
function i(c, a) {
if (!o[c]) {
if (!e[c]) {
var s = c.split("/");
s = s[s.length - 1];
if (!e[s]) {
var u = "function" == typeof __require && __require;
if (!a && u) return u(s, !0);
if (r) return r(s, !0);
throw new Error("Cannot find module '" + c + "'");
}
c = s;
}
var l = o[c] = {
exports: {}
};
e[c][0].call(l.exports, function(t) {
return i(e[c][1][t] || t);
}, l, l.exports, t, e, o, n);
}
return o[c].exports;
}
for (var r = "function" == typeof __require && __require, c = 0; c < n.length; c++) i(n[c]);
return i;
}({
DataManager: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "1f70fF7V/9I3LW6rm6Y+Vv9", "DataManager");
Object.defineProperty(o, "__esModule", {
value: !0
});
var n = function() {
function t() {
this.curSoundIsClose = !0;
this.curSoundBGIsClose = !0;
this.curGameIsRun = !1;
this.userId = "10086";
this._curScord = 0;
this.curWinNum = 0;
this.randRes = -1;
this.canClick = !0;
this.itemHideAniIsPlay = !1;
this.curWinItmeIndex = -1;
this.curWinData = [];
this.gameLayerScr = null;
this.startTime = 30;
this._indexTime = 30;
this.timerFunc = null;
this.tipNum = -1;
}
Object.defineProperty(t.prototype, "curScord", {
get: function() {
return this._curScord;
},
set: function(t) {
this._curScord = t;
this.gameLayerScr && this.gameLayerScr.updateUserCoin();
},
enumerable: !1,
configurable: !0
});
Object.defineProperty(t.prototype, "indexTime", {
get: function() {
return this._indexTime;
},
set: function(t) {
this._indexTime = t;
if (this.gameLayerScr) {
this.gameLayerScr.updateTimerUi();
t == this.startTime && this.gameLayerScr.unschedule(this.timerFunc);
}
},
enumerable: !1,
configurable: !0
});
t.instance = new t();
return t;
}();
o.default = n.instance;
cc._RF.pop();
}, {} ],
EventMgr: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "d0344zMoipJG7vJVPYxiAp2", "EventMgr");
Object.defineProperty(o, "__esModule", {
value: !0
});
var n = t("./Event"), i = function() {
function t() {
this.eventMap = new Map();
}
Object.defineProperty(t, "Instance", {
get: function() {
null == this.instance && (this.instance = new t());
return this.instance;
},
enumerable: !1,
configurable: !0
});
t.prototype.Register = function(t, e, o) {
void 0 === o && (o = null);
var i = new n.default(t, e, !1, o);
this.setEvent(t, i);
};
t.prototype.Once = function(t, e, o) {
void 0 === o && (o = null);
var i = new n.default(t, e, !0, o);
this.setEvent(t, i);
};
t.prototype.Off = function() {
this.eventMap = new Map();
};
t.prototype.Emit = function(t) {
for (var e = [], o = 1; o < arguments.length; o++) e[o - 1] = arguments[o];
if (this.eventMap.has(t)) {
var n = this.eventMap.get(t);
if (n.length) {
for (var i = new Array(), r = 0; r < n.length; r++) {
var c = n[r];
c.Call.apply(c, e);
c.Once || i.push(c);
}
this.eventMap.set(t, i);
}
}
};
t.prototype.setEvent = function(t, e) {
if (this.eventMap.has(t)) {
var o = (n = this.eventMap.get(t)).findIndex(function(t) {
return t.Equel(e);
});
if (-1 == o) {
n.push(e);
this.eventMap.set(t, n);
} else {
n.splice(o, 1);
n.push(e);
this.eventMap.set(t, n);
}
} else {
var n;
(n = new Array()).push(e);
this.eventMap.set(t, n);
}
};
return t;
}();
o.default = i;
cc._RF.pop();
}, {
"./Event": "Event"
} ],
Event: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "0fa26nTHQ9H/63+pumdJtCd", "Event");
Object.defineProperty(o, "__esModule", {
value: !0
});
var n = function() {
function t(t, e, o, n) {
void 0 === n && (n = null);
this.EventId = t;
this.Callback = e;
this.Scope = n;
this.RealCallBakc = null != n || null != n ? e.bind(n) : this.Callback;
this.Once = o;
}
Object.defineProperty(t.prototype, "Call", {
get: function() {
return this.RealCallBakc;
},
enumerable: !1,
configurable: !0
});
t.prototype.Equel = function(t) {
return this.EventId == t.EventId && this.Callback == t.Callback && this.Once == t.Once && this.Scope == t.Scope;
};
return t;
}();
o.default = n;
cc._RF.pop();
}, {} ],
GameLayer: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "5fa5exMMXFKupMg6i92JxBn", "GameLayer");
var n, i = this && this.__extends || (n = function(t, e) {
return (n = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
n(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), r = this && this.__decorate || function(t, e, o, n) {
var i, r = arguments.length, c = r < 3 ? e : null === n ? n = Object.getOwnPropertyDescriptor(e, o) : n;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(t, e, o, n); else for (var a = t.length - 1; a >= 0; a--) (i = t[a]) && (c = (r < 3 ? i(c) : r > 3 ? i(e, o, c) : i(e, o)) || c);
return r > 3 && c && Object.defineProperty(e, o, c), c;
}, c = this && this.__awaiter || function(t, e, o, n) {
return new (o || (o = Promise))(function(i, r) {
function c(t) {
try {
s(n.next(t));
} catch (t) {
r(t);
}
}
function a(t) {
try {
s(n.throw(t));
} catch (t) {
r(t);
}
}
function s(t) {
t.done ? i(t.value) : (e = t.value, e instanceof o ? e : new o(function(t) {
t(e);
})).then(c, a);
var e;
}
s((n = n.apply(t, e || [])).next());
});
}, a = this && this.__generator || function(t, e) {
var o, n, i, r, c = {
label: 0,
sent: function() {
if (1 & i[0]) throw i[1];
return i[1];
},
trys: [],
ops: []
};
return r = {
next: a(0),
throw: a(1),
return: a(2)
}, "function" == typeof Symbol && (r[Symbol.iterator] = function() {
return this;
}), r;
function a(t) {
return function(e) {
return s([ t, e ]);
};
}
function s(r) {
if (o) throw new TypeError("Generator is already executing.");
for (;c; ) try {
if (o = 1, n && (i = 2 & r[0] ? n.return : r[0] ? n.throw || ((i = n.return) && i.call(n), 
0) : n.next) && !(i = i.call(n, r[1])).done) return i;
(n = 0, i) && (r = [ 2 & r[0], i.value ]);
switch (r[0]) {
case 0:
case 1:
i = r;
break;

case 4:
c.label++;
return {
value: r[1],
done: !1
};

case 5:
c.label++;
n = r[1];
r = [ 0 ];
continue;

case 7:
r = c.ops.pop();
c.trys.pop();
continue;

default:
if (!(i = c.trys, i = i.length > 0 && i[i.length - 1]) && (6 === r[0] || 2 === r[0])) {
c = 0;
continue;
}
if (3 === r[0] && (!i || r[1] > i[0] && r[1] < i[3])) {
c.label = r[1];
break;
}
if (6 === r[0] && c.label < i[1]) {
c.label = i[1];
i = r;
break;
}
if (i && c.label < i[2]) {
c.label = i[2];
c.ops.push(r);
break;
}
i[2] && c.ops.pop();
c.trys.pop();
continue;
}
r = e.call(t, c);
} catch (t) {
r = [ 6, t ];
n = 0;
} finally {
o = i = 0;
}
if (5 & r[0]) throw r[1];
return {
value: r[0] ? r[1] : void 0,
done: !0
};
}
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var s = t("./DataManager"), u = t("./ItemNode"), l = t("./util/define"), p = t("./util/event/EventMgr"), d = t("./util/loaderManager"), h = t("./util/util"), f = cc._decorator, y = f.ccclass, g = f.property, m = function(t) {
i(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.itemResList = [];
e.userCoinNode = null;
e.tipNode = null;
e.resultNode = null;
e.timerNode = null;
e.soundBtn = null;
e.musicBtn = null;
e.playBtn = null;
e.gzPos = null;
e.gamePos = null;
e.audioResList = [];
e.iconPf = null;
e.index = 0;
e.colNum = 4;
e.rowNum = 4;
e.alreadyDrawLineList = [];
e.curDrawLineItmeIndex = [];
e.list = [];
return e;
}
e.prototype.loadCard = function() {
return c(this, void 0, void 0, function() {
var t;
return a(this, function(e) {
switch (e.label) {
case 0:
t = this;
return [ 4, d.default.getRes("item", "prefab", cc.Prefab) ];

case 1:
t.iconPf = e.sent();
this.iconPf && console.log("预制体加载成功！");
return [ 2 ];
}
});
});
};
e.prototype.start = function() {
this.updateUserCoin();
this.updateTimerUi();
};
e.prototype.listerEvent = function() {
p.default.Instance.Register(l.EventId.Result, this.showResult, this);
};
e.prototype.cleatEvent = function() {
p.default.Instance.Off();
};
e.prototype.btnEvent = function(t) {
var e = t.target.name;
this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
this.node.getComponent(cc.AudioSource).play();
switch (e) {
case "btnStartGame":
this.playGame();
break;

case "btnReturn":
this.hideResultNode();
this.cleatEvent();
cc.director.loadScene("a_startGame");
break;

case "btNextGame":
case "btStartOver":
this.hideResultNode();
break;

case "btExit":
this.hideResultNode();
this.cleatEvent();
cc.director.loadScene("a_startGame");
break;

case "tipBtn":
this.openTipNode();
break;

case "closeTipBtn":
this.hideTipNode();
break;

case "btnSound":
this.openOrCloseSound();
break;

case "musicBtn":
this.openOrCloseBG();
}
};
e.prototype.playGame = function() {
if (!s.default.curGameIsRun) {
s.default.curGameIsRun = !0;
this.startTimer();
this.node.getComponent(cc.AudioSource).clip = this.audioResList[2];
this.node.getComponent(cc.AudioSource).play();
var t = h.default.getRandomListItme([ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ], 20, !1);
this.list = t;
this.creatLaber();
for (var e = 0; e < t.length; e++) this.creatFish(e, t[e], this.gzPos.children[e]);
}
};
e.prototype.creatFish = function(t, e, o) {
var n = this;
o.getComponent(cc.Sprite).spriteFrame = this.itemResList[e];
o.on(cc.Node.EventType.TOUCH_END, function() {
console.log("当前点击的", e, s.default.tipNum);
if (e == s.default.tipNum) {
n.unschedule(n.callTimer);
n.creatLaber();
s.default._curScord += 100;
n.updataCoin();
var t = h.default.getRandom(0, 15);
e = t;
o.getComponent(cc.Sprite).spriteFrame = n.itemResList[e];
}
});
};
e.prototype.creatLaber = function() {
var t = this;
cc.tween(this.gamePos.children[0]).to(.1, {
scale: 1.5
}).to(.2, {
scale: 1
}).call(function() {
var e = h.default.getRandom(0, 15);
t.gamePos.children[0].getComponent(cc.Sprite).spriteFrame = t.itemResList[e];
s.default.tipNum = e;
}).start();
this.callTimer = function() {
var e = h.default.getRandom(0, 15);
t.gamePos.children[0].getComponent(cc.Sprite).spriteFrame = t.itemResList[e];
s.default.tipNum = e;
};
this.schedule(this.callTimer, 3);
};
e.prototype.listTouchEvent = function(t) {
var e = this;
t.on(cc.Node.EventType.TOUCH_START, function(e) {
t.startPos = cc.v2(e.getLocation().x, e.getLocation().y);
});
t.on(cc.Node.EventType.TOUCH_CANCEL, function(o) {
var n = t.startPos, i = cc.v2(o.getLocation().x, o.getLocation().y), r = e.isDirection(n, i);
r && e.TouchMove(t, r);
});
};
e.prototype.TouchMove = function(t, e) {
var o = this, n = t.getComponent(u.default).itemIndex, i = n, r = null;
s.default._curScord += 1;
this.updataCoin();
switch (e) {
case l.DirectionType.Top:
console.log("上");
n - this.colNum >= 0 && (i = n - this.colNum);
break;

case l.DirectionType.Bottom:
console.log("下");
n + this.colNum <= this.gzPos.children.length && (i = n + this.colNum);
break;

case l.DirectionType.Left:
console.log("左");
n % this.colNum - 1 >= 0 && (i = n - 1);
break;

case l.DirectionType.Right:
console.log("右");
n % this.colNum + 1 <= this.colNum && (i = n + 1);
}
this.gamePos.children.forEach(function(t) {
t.getComponent(u.default).itemIndex == i && (r = t);
});
if (r) {
cc.tween(t).to(.2, {
position: this.gzPos.children[i].position
}).start();
cc.tween(r).to(.2, {
position: this.gzPos.children[n].position
}).start();
this.scheduleOnce(function() {
t.getComponent(u.default).itemIndex = i;
r.getComponent(u.default).itemIndex = n;
var e = h.default.copyObj(t.getComponent(u.default).itemId);
t.getComponent(u.default).itemId = r.getComponent(u.default).itemId;
r.getComponent(u.default).itemId = e;
var c = [];
o.gamePos.children.forEach(function(t) {
c.push(t.getComponent(u.default).itemId);
o.showResult(!0);
});
}, .3);
}
};
e.prototype.updataIndex = function() {
for (var t = 0; t < this.gamePos.children.length - 1; t++) this.gamePos.children[t].getComponent(u.default).itemIndex;
};
e.prototype.isDirection = function(t, e) {
l.DirectionType.Left;
return Math.abs(e.x - t.x) >= Math.abs(e.y - t.y) ? e.x > t.x ? l.DirectionType.Right : l.DirectionType.Left : e.y > t.y ? l.DirectionType.Top : l.DirectionType.Bottom;
};
e.prototype.getCurWorldPosItem = function(t) {
var e = null;
this.gamePos.children.forEach(function(o) {
var n = o.convertToWorldSpaceAR(cc.v2(0, 0)), i = o.getContentSize();
t.x > n.x - i.width && t.x < n.x + i.width && t.y > n.y - i.height && t.y < n.y + i.height && (e = o);
});
return e;
};
e.prototype.openOrCloseSound = function() {
if (s.default.curSoundBGIsClose) {
this.soundBtn.color = cc.color(170, 170, 170, 255);
this.node.getComponent(cc.AudioSource).volume = 0;
} else {
this.soundBtn.color = cc.color(255, 255, 255, 255);
this.node.getComponent(cc.AudioSource).volume = 1;
}
s.default.curSoundBGIsClose = !s.default.curSoundBGIsClose;
};
e.prototype.openOrCloseBG = function() {
if (s.default.curSoundIsClose) {
this.musicBtn.color = cc.color(170, 170, 170, 255);
cc.find("Canvas").getComponent(cc.AudioSource).volume = 0;
} else {
this.musicBtn.color = cc.color(255, 255, 255, 255);
cc.find("Canvas").getComponent(cc.AudioSource).volume = 1;
}
s.default.curSoundIsClose = !s.default.curSoundIsClose;
};
e.prototype.startTimer = function() {
var t = this;
s.default.timerFunc = function() {
s.default.indexTime -= .01;
s.default.indexTime <= 0 && t.ResultFn();
t.updateTimerUi();
t.timerNode.getChildByName("timeText").getComponent(cc.Label).string = Math.floor(s.default.indexTime) + "s";
};
this.schedule(s.default.timerFunc, .01);
};
e.prototype.updateTimerUi = function() {
cc.find("barBg/bar", this.timerNode).getComponent(cc.Sprite).fillRange = s.default.indexTime / s.default.startTime;
this.timerNode.getChildByName("timeText").getComponent(cc.Label).string = Math.ceil(s.default.indexTime) + "s";
};
e.prototype.updataCoin = function() {
this.updateUserCoin();
this.node.getComponent(cc.AudioSource).clip = this.audioResList[2];
this.node.getComponent(cc.AudioSource).play();
};
e.prototype.updateUserCoin = function() {
var t = this.userCoinNode.getChildByName("coinLable");
cc.tween(t).to(.1, {
scale: 1.1
}).to(.1, {
scale: 1
}).start();
t.getComponent(cc.Label).string = "" + s.default.curScord;
};
e.prototype.ResultFn = function() {
if (s.default._curScord >= 1e3) {
this.showResult(!0);
s.default.curWinNum += 200;
} else this.showResult(!1);
};
e.prototype.openTipNode = function() {
this.tipNode.getChildByName("rule").scale = .8;
this.tipNode.active = !0;
cc.tween(this.tipNode.getChildByName("rule")).to(.2, {
scale: 1
}).start();
};
e.prototype.hideTipNode = function() {
var t = this;
cc.tween(this.tipNode.getChildByName("rule")).to(.2, {
scale: .5
}).call(function() {
t.tipNode.active = !1;
t.tipNode.getChildByName("rule").scale = 1;
}).start();
};
e.prototype.showResult = function(t) {
this.unschedule(s.default.timerFunc);
this.unscheduleAllCallbacks();
this.gzPos.children.forEach(function(t) {
t.off(cc.Node.EventType.TOUCH_END);
});
s.default.indexTime = s.default.startTime;
if (t) {
var e = cc.find("win/winNum", this.resultNode);
s.default.curWinNum += 100;
e.getComponent(cc.Label).string = "" + s.default.curWinNum;
}
this.node.getComponent(cc.AudioSource).clip = this.audioResList[t ? 4 : 5];
this.node.getComponent(cc.AudioSource).play();
var o = this.resultNode.getChildByName("win"), n = this.resultNode.getChildByName("lose");
o.active = t;
n.active = !t;
var i = t ? o : n;
this.resultNode.active = !0;
i.scale = .6;
i.opacity = 100;
cc.tween(i).to(.3, {
scale: 1.1,
opacity: 255
}).to(.3, {
scale: 1
}).start();
};
e.prototype.hideResultNode = function() {
s.default.curGameIsRun = !1;
this.resultNode.active = !1;
cc.director.getCollisionManager().enabled = !1;
s.default._curScord = 0;
s.default._indexTime = s.default.startTime;
this.updateTimerUi();
this.updateUserCoin();
};
r([ g({
type: [ cc.SpriteFrame ],
tooltip: "元素纹理"
}) ], e.prototype, "itemResList", void 0);
r([ g({
type: cc.Node,
tooltip: "用户余额节点"
}) ], e.prototype, "userCoinNode", void 0);
r([ g({
type: cc.Node,
tooltip: "游戏提示页面"
}) ], e.prototype, "tipNode", void 0);
r([ g({
type: cc.Node,
tooltip: "游戏结果节点"
}) ], e.prototype, "resultNode", void 0);
r([ g({
type: cc.Node,
tooltip: "倒计时节点"
}) ], e.prototype, "timerNode", void 0);
r([ g({
type: cc.Node,
tooltip: "音效按钮节点"
}) ], e.prototype, "soundBtn", void 0);
r([ g({
type: cc.Node,
tooltip: "音效按钮节点"
}) ], e.prototype, "musicBtn", void 0);
r([ g({
type: cc.Node,
tooltip: "开始游戏节点"
}) ], e.prototype, "playBtn", void 0);
r([ g({
type: cc.Node,
tooltip: "游戏格子"
}) ], e.prototype, "gzPos", void 0);
r([ g({
type: cc.Node,
tooltip: "游戏格子"
}) ], e.prototype, "gamePos", void 0);
r([ g({
type: [ cc.AudioClip ]
}) ], e.prototype, "audioResList", void 0);
return r([ y ], e);
}(cc.Component);
o.default = m;
cc._RF.pop();
}, {
"./DataManager": "DataManager",
"./ItemNode": "ItemNode",
"./util/define": "define",
"./util/event/EventMgr": "EventMgr",
"./util/loaderManager": "loaderManager",
"./util/util": "util"
} ],
GameWheel: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "18a0cX5k81IMrDI6b1T6Rlf", "GameWheel");
var n, i = this && this.__extends || (n = function(t, e) {
return (n = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
n(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), r = this && this.__decorate || function(t, e, o, n) {
var i, r = arguments.length, c = r < 3 ? e : null === n ? n = Object.getOwnPropertyDescriptor(e, o) : n;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(t, e, o, n); else for (var a = t.length - 1; a >= 0; a--) (i = t[a]) && (c = (r < 3 ? i(c) : r > 3 ? i(e, o, c) : i(e, o)) || c);
return r > 3 && c && Object.defineProperty(e, o, c), c;
};
Object.defineProperty(o, "__esModule", {
value: !0
});
o.AREA_COUNT_LIST = o.WHEEL_TYPES = void 0;
var c = t("./util/define"), a = cc._decorator, s = a.ccclass, u = a.property, l = [ 14.35, 45, 22.5 ];
o.WHEEL_TYPES = {
MINI: 0,
MEDIUM: 1,
MAX: 2
};
o.AREA_COUNT_LIST = [ 25, 8, 16 ];
var p = function(t) {
i(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.wheelNodes = [];
e.lightNode = null;
e.accelerated = 0;
e.deceleration = 0;
e.maxRangeSpeed = 0;
e._curWheelType = o.WHEEL_TYPES.MINI;
e._range = 0;
e._currentRotationSpeed = 0;
e._targetRotation = 0;
e._totalPrize = 0;
e._resultId = 0;
e._lotteryId = 0;
e._interval = 0;
e._currentState = c.WheelState.Stand;
e._mixRotation = 0;
e._wheelConfig = [];
e._maxTargetNode = null;
e._isPlayEndSound = !1;
e.endCall = null;
return e;
}
e.prototype.onLoad = function() {
this.resetAngle();
};
e.prototype.updateWheelConfig = function(t) {
var e = this;
this.resetWheel();
if (!(this._wheelConfig.length > 0)) {
this._wheelConfig = [];
var o;
t.forEach(function(t) {
o = {};
if (t.value >= 0) {
o.type = c.WheelType.BetLv;
o.num = t.value / 100;
} else {
o.type = c.WheelType.Spin;
o.num = Math.abs(t.value) / 100;
}
e._wheelConfig.push(o);
});
this.init();
}
};
e.prototype.init = function() {
this.initWheel();
};
e.prototype.initWheel = function() {
var t = this.wheelNodes[this._curWheelType].children, e = 0;
if (this.wheelNodes[this._curWheelType]) for (var n = 0; n < o.AREA_COUNT_LIST[this._curWheelType]; n++) if (this._wheelConfig[n].type == c.WheelType.BetLv) {
if (this._wheelConfig[n].num > e) {
e = this._wheelConfig[n].num;
this._maxTargetNode = t[n];
}
} else this._wheelConfig[n].type, c.WheelType.Spin;
this.resetAngle();
};
e.prototype.initProperties = function() {
this._range = 360;
this._currentRotationSpeed = 0;
this._totalPrize = this.wheelNodes[this._curWheelType].children.length;
this._resultId = this._totalPrize + 1 - this._resultId;
this._interval = .02;
this.accelerated = 2160;
this.deceleration = -720;
this.maxRangeSpeed = 1440;
this._isPlayEndSound = !1;
};
e.prototype.runGame = function(t, e) {
this.endCall = e;
this._resultId = t;
this._lotteryId = t;
console.log("中奖id =" + this._resultId);
this.initProperties();
this.run();
};
e.prototype.resetWheel = function() {
this.unschedule(this.updateRotation);
this._currentRotationSpeed = 0;
this._currentState = c.WheelState.Stand;
};
e.prototype.showWheelEnd = function() {
this.unschedule(this.updateRotation);
this._currentRotationSpeed = 0;
this._currentState = c.WheelState.Stand;
this.wheelNodes[this._curWheelType].angle = this._lotteryId * l[this._curWheelType];
this.endCall && this.endCall();
console.log("滚动结束");
};
e.prototype.run = function() {
if (this.getRunning()) console.log("转盘已经开始转动..."); else {
this._currentState = c.WheelState.Acelerara;
this.schedule(this.updateRotation, this._interval);
}
};
e.prototype.stop = function() {
this.resetWheel();
this.endCall && this.endCall();
};
e.prototype.onVirtualCompute = function() {
for (var t = 0, e = this.maxRangeSpeed; e > 0; ) {
t += this._interval * e;
e += this._interval * this.deceleration;
}
return t;
};
e.prototype.onGetValue = function(t) {
var e = t - this.onVirtualCompute();
if (e > 0) for (;e >= 360; ) e -= this._range; else for (;e < 0; ) e += this._range;
return e;
};
e.prototype.detectionAngle = function() {
var t = this._range - l[this._curWheelType] * (2 + this._curWheelType);
this._targetRotation = t - (o.AREA_COUNT_LIST[this._curWheelType] - this._resultId) * l[this._curWheelType];
this._targetRotation = this._targetRotation;
var e = this.onGetValue(this._targetRotation);
this.wheelNodes[this._curWheelType].angle = -e;
this._currentState = c.WheelState.Desacelerar;
};
e.prototype.updateRotation = function() {
console.log("update curState= " + this._currentState);
switch (this._currentState) {
case 0:
break;

case 1:
if (this._currentRotationSpeed >= this.maxRangeSpeed) {
this._currentRotationSpeed = this.maxRangeSpeed;
this.detectionAngle();
} else this._currentRotationSpeed += this.accelerated * this._interval;
break;

case 2:
if (this._currentRotationSpeed <= 0) {
this._currentRotationSpeed = 0;
this._currentState = c.WheelState.Stand;
this.stop();
} else {
this.maxRangeSpeed, this._currentRotationSpeed;
this.maxRangeSpeed, this._currentRotationSpeed;
this.maxRangeSpeed, this._currentRotationSpeed;
if (this._currentRotationSpeed <= 50) {
var t = Math.floor(Math.abs(this.wheelNodes[this._curWheelType].angle / 360));
this._mixRotation = 360 * t + this._targetRotation - Math.abs(this.wheelNodes[this._curWheelType].angle);
this.stop();
return;
}
this._currentRotationSpeed += this.deceleration * this._interval;
}
break;

default:
this.stop();
}
var e = this._currentRotationSpeed * this._interval;
this.wheelNodes[this._curWheelType].angle -= e;
};
e.prototype.getRandom = function(t, e) {
return Math.floor(Math.random() * (e - t + 1) + t);
};
e.prototype.getRandomIndex = function(t) {
return t <= 0 ? 0 : Math.round(Math.random() * t);
};
e.prototype.getRunning = function() {
return this._currentState > c.WheelState.Stand;
};
e.prototype.getTargetNode = function() {
var t = this.wheelNodes[this._curWheelType].children[0];
if (t) return t;
};
e.prototype.resetAngle = function() {
this.wheelNodes[this._curWheelType].angle = 0;
};
e.prototype.update = function() {};
r([ u(cc.Node) ], e.prototype, "wheelNodes", void 0);
r([ u({
type: cc.Node
}) ], e.prototype, "lightNode", void 0);
r([ u({
displayName: "加速度",
tooltip: "加速度值,每秒速度增加几度,°/s²"
}) ], e.prototype, "accelerated", void 0);
r([ u({
displayName: "减速度",
tooltip: "加速度值,每秒速度减少几度,°/s²"
}) ], e.prototype, "deceleration", void 0);
r([ u({
displayName: "最大速度",
tooltip: "每秒速度减少几度,°/s"
}) ], e.prototype, "maxRangeSpeed", void 0);
return r([ s ], e);
}(cc.Component);
o.default = p;
cc._RF.pop();
}, {
"./util/define": "define"
} ],
HallManger: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "aebc05iEkpIa6XeWy1zw3Ot", "HallManger");
var n, i = this && this.__extends || (n = function(t, e) {
return (n = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
n(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), r = this && this.__decorate || function(t, e, o, n) {
var i, r = arguments.length, c = r < 3 ? e : null === n ? n = Object.getOwnPropertyDescriptor(e, o) : n;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(t, e, o, n); else for (var a = t.length - 1; a >= 0; a--) (i = t[a]) && (c = (r < 3 ? i(c) : r > 3 ? i(e, o, c) : i(e, o)) || c);
return r > 3 && c && Object.defineProperty(e, o, c), c;
}, c = this && this.__awaiter || function(t, e, o, n) {
return new (o || (o = Promise))(function(i, r) {
function c(t) {
try {
s(n.next(t));
} catch (t) {
r(t);
}
}
function a(t) {
try {
s(n.throw(t));
} catch (t) {
r(t);
}
}
function s(t) {
t.done ? i(t.value) : (e = t.value, e instanceof o ? e : new o(function(t) {
t(e);
})).then(c, a);
var e;
}
s((n = n.apply(t, e || [])).next());
});
}, a = this && this.__generator || function(t, e) {
var o, n, i, r, c = {
label: 0,
sent: function() {
if (1 & i[0]) throw i[1];
return i[1];
},
trys: [],
ops: []
};
return r = {
next: a(0),
throw: a(1),
return: a(2)
}, "function" == typeof Symbol && (r[Symbol.iterator] = function() {
return this;
}), r;
function a(t) {
return function(e) {
return s([ t, e ]);
};
}
function s(r) {
if (o) throw new TypeError("Generator is already executing.");
for (;c; ) try {
if (o = 1, n && (i = 2 & r[0] ? n.return : r[0] ? n.throw || ((i = n.return) && i.call(n), 
0) : n.next) && !(i = i.call(n, r[1])).done) return i;
(n = 0, i) && (r = [ 2 & r[0], i.value ]);
switch (r[0]) {
case 0:
case 1:
i = r;
break;

case 4:
c.label++;
return {
value: r[1],
done: !1
};

case 5:
c.label++;
n = r[1];
r = [ 0 ];
continue;

case 7:
r = c.ops.pop();
c.trys.pop();
continue;

default:
if (!(i = c.trys, i = i.length > 0 && i[i.length - 1]) && (6 === r[0] || 2 === r[0])) {
c = 0;
continue;
}
if (3 === r[0] && (!i || r[1] > i[0] && r[1] < i[3])) {
c.label = r[1];
break;
}
if (6 === r[0] && c.label < i[1]) {
c.label = i[1];
i = r;
break;
}
if (i && c.label < i[2]) {
c.label = i[2];
c.ops.push(r);
break;
}
i[2] && c.ops.pop();
c.trys.pop();
continue;
}
r = e.call(t, c);
} catch (t) {
r = [ 6, t ];
n = 0;
} finally {
o = i = 0;
}
if (5 & r[0]) throw r[1];
return {
value: r[0] ? r[1] : void 0,
done: !0
};
}
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var s = t("./DataManager"), u = t("./recordsItem"), l = t("./util/loaderManager"), p = t("./util/util"), d = cc._decorator, h = d.ccclass, f = d.property, y = function(t) {
i(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.audioResList = [];
e.tipNode = null;
e.soundBtn = null;
e.userInfo = null;
e.contentLayout = null;
e.PromoPage = null;
e.chartsPage = null;
e.chartsLayout = null;
e.iconPf = null;
return e;
}
e.prototype.loadCard = function() {
return c(this, void 0, void 0, function() {
var t;
return a(this, function(e) {
switch (e.label) {
case 0:
t = this;
return [ 4, l.default.getRes("recordsItem", "prefab", cc.Prefab) ];

case 1:
t.iconPf = e.sent();
this.iconPf;
return [ 2 ];
}
});
});
};
e.prototype.start = function() {
this.loadCard();
this.upadtaUserInfo();
this.updateUserNum();
this.listeBtnAni();
};
e.prototype.lodingRecord = function() {
for (var t = 1; t <= 8; t++) this.instantNode(t);
this.chartsLayout.getComponent(cc.Layout).updateLayout();
};
e.prototype.instantNode = function(t) {
var e = cc.instantiate(this.iconPf);
this.chartsLayout.addChild(e);
e.setPosition(0, 0);
e.getComponent(u.default).init(t);
};
e.prototype.btnEvent = function(t) {
var e = t.target.name;
this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
this.node.getComponent(cc.AudioSource).play();
switch (e) {
case "btnStartGame":
case "icon1":
this.node.getComponent(cc.AudioSource).clip = this.audioResList[1];
this.node.getComponent(cc.AudioSource).play();
cc.director.loadScene("game");
break;

case "backBtn":
this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
this.node.getComponent(cc.AudioSource).play();
cc.director.loadScene("a_startGame");
break;

case "tipBtn":
this.openTipNode();
break;

case "closeTipBtn":
this.hideTipNode();
break;

case "soundBtn":
this.openOrCloseSound();
break;

case "shareBtn":
this.shareFn();
break;

case "closePromoBtn":
this.closePromo();
break;

case "closeChartsBtn":
this.closeChart();
}
};
e.prototype.listeBtnAni = function() {
this.contentLayout.children.forEach(function(t) {
t.on(cc.Node.EventType.TOUCH_END, function() {
cc.tween(t).to(.2, {
scale: 1.1
}).to(.1, {
scale: 1
}).start();
});
});
};
e.prototype.openTipNode = function() {
this.tipNode.getChildByName("rule").scale = .8;
this.tipNode.active = !0;
cc.tween(this.tipNode.getChildByName("rule")).to(.2, {
scale: 1
}).start();
};
e.prototype.hideTipNode = function() {
var t = this;
cc.tween(this.tipNode.getChildByName("rule")).to(.2, {
scale: .5
}).call(function() {
t.tipNode.active = !1;
t.tipNode.getChildByName("rule").scale = 1;
}).start();
};
e.prototype.closePromo = function() {
this.PromoPage.active = !1;
this.PromoPage.getChildByName("rule").getChildByName("EditBox").getComponent(cc.EditBox).string = "";
};
e.prototype.closeChart = function() {
this.chartsPage.active = !1;
};
e.prototype.openPromo = function() {
this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
this.node.getComponent(cc.AudioSource).play();
this.PromoPage.getChildByName("rule").scale = 1.2;
this.PromoPage.active = !0;
cc.tween(this.PromoPage.getChildByName("rule")).to(.2, {
scale: 1
}).start();
};
e.prototype.openCharts = function() {
this.lodingRecord();
this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
this.node.getComponent(cc.AudioSource).play();
this.chartsPage.getChildByName("rule").scale = 1.2;
this.chartsPage.active = !0;
cc.tween(this.chartsPage.getChildByName("rule")).to(.2, {
scale: 1
}).start();
};
e.prototype.openOrCloseSound = function() {
if (s.default.curSoundIsClose) {
this.soundBtn.children[0].color = cc.color(170, 170, 170, 255);
this.soundBtn.children[1].active = !0;
cc.find("Canvas").getComponent(cc.AudioSource).volume = 0;
this.node.getComponent(cc.AudioSource).volume = 0;
} else {
this.soundBtn.children[0].color = cc.color(255, 255, 255, 255);
this.soundBtn.children[1].active = !1;
cc.find("Canvas").getComponent(cc.AudioSource).volume = 1;
this.node.getComponent(cc.AudioSource).volume = 1;
}
s.default.curSoundIsClose = !s.default.curSoundIsClose;
};
e.prototype.upadtaUserInfo = function() {
this.userInfo.getChildByName("userID").getComponent(cc.Label).string = "ID:" + s.default.userId;
this.userInfo.getChildByName("scoreLaberl").getComponent(cc.Label).string = "" + s.default.curWinNum;
};
e.prototype.updateUserNum = function() {
var t = p.default.getRandArray(100, 5e3, this.contentLayout.children.length);
this.contentLayout.children.forEach(function(e, o) {
e.getChildByName("num").getComponent(cc.Label).string = t[o] + "";
});
};
e.prototype.shareFn = function() {};
r([ f({
type: [ cc.AudioClip ],
tooltip: "音效数组"
}) ], e.prototype, "audioResList", void 0);
r([ f({
type: cc.Node,
tooltip: "游戏提示页面"
}) ], e.prototype, "tipNode", void 0);
r([ f({
type: cc.Node,
tooltip: "音效按钮节点"
}) ], e.prototype, "soundBtn", void 0);
r([ f({
type: cc.Node,
tooltip: "用户信息"
}) ], e.prototype, "userInfo", void 0);
r([ f({
type: cc.Node,
tooltip: "icon节点"
}) ], e.prototype, "contentLayout", void 0);
r([ f({
type: cc.Node,
tooltip: "兑换奖励框"
}) ], e.prototype, "PromoPage", void 0);
r([ f({
type: cc.Node,
tooltip: "排行榜页面"
}) ], e.prototype, "chartsPage", void 0);
r([ f({
type: cc.Node,
tooltip: "排行榜Layout"
}) ], e.prototype, "chartsLayout", void 0);
return r([ h ], e);
}(cc.Component);
o.default = y;
cc._RF.pop();
}, {
"./DataManager": "DataManager",
"./recordsItem": "recordsItem",
"./util/loaderManager": "loaderManager",
"./util/util": "util"
} ],
ItemNode: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "1dde00z82lJAqrLsgVLephC", "ItemNode");
var n, i = this && this.__extends || (n = function(t, e) {
return (n = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
n(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), r = this && this.__decorate || function(t, e, o, n) {
var i, r = arguments.length, c = r < 3 ? e : null === n ? n = Object.getOwnPropertyDescriptor(e, o) : n;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(t, e, o, n); else for (var a = t.length - 1; a >= 0; a--) (i = t[a]) && (c = (r < 3 ? i(c) : r > 3 ? i(e, o, c) : i(e, o)) || c);
return r > 3 && c && Object.defineProperty(e, o, c), c;
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var c = cc._decorator, a = c.ccclass, s = c.property, u = function(t) {
i(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.imgSp = null;
e.itemId = 0;
e.itemIndex = -1;
return e;
}
e.prototype.start = function() {};
e.prototype.init = function(t, e) {
this.itemId = t;
this.itemIndex = e;
this.imgSp.string = 0 == t ? "" : t + "";
};
r([ s(cc.Label) ], e.prototype, "imgSp", void 0);
return r([ a ], e);
}(cc.Component);
o.default = u;
cc._RF.pop();
}, {} ],
JumpStr: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "79f41Y4MNRPKK6EgrncSreh", "JumpStr");
var n, i = this && this.__extends || (n = function(t, e) {
return (n = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
n(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), r = this && this.__decorate || function(t, e, o, n) {
var i, r = arguments.length, c = r < 3 ? e : null === n ? n = Object.getOwnPropertyDescriptor(e, o) : n;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(t, e, o, n); else for (var a = t.length - 1; a >= 0; a--) (i = t[a]) && (c = (r < 3 ? i(c) : r > 3 ? i(e, o, c) : i(e, o)) || c);
return r > 3 && c && Object.defineProperty(e, o, c), c;
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var c = cc._decorator, a = c.ccclass, s = c.property, u = function(t) {
i(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.str = "";
e.fontSize = 0;
e.aniTime = 0;
e.oulineWidth = 1;
e.isOulin = !0;
e.oulineColor = cc.color(0, 0, 0);
return e;
}
e.prototype.start = function() {
var t = this, e = this.node.addComponent(cc.Layout);
e.type = cc.Layout.Type.HORIZONTAL;
e.resizeMode = cc.Layout.ResizeMode.CONTAINER;
for (var o = 0; o < this.str.length; o++) {
var n = this.str[o], i = new cc.Node(), r = i.addComponent(cc.Label);
if (this.isOulin) {
var c = i.addComponent(cc.LabelOutline);
c.color = this.oulineColor;
c.width = this.oulineWidth;
}
r.lineHeight = this.fontSize;
r.string = n;
r.fontSize = this.fontSize;
this.node.addChild(i);
}
this.playStrJump();
this.schedule(function() {
t.playStrJump();
}, this.aniTime * this.str.length / 2 + .2);
};
e.prototype.playStrJump = function() {
var t = this, e = this.aniTime / 2, o = 0, n = function(i) {
cc.tween(i).sequence(cc.tween().to(e, {
y: t.fontSize / 2
}), cc.tween().to(e / 4 * 3, {
y: -t.fontSize / 3
}), cc.tween().to(e / 4, {
y: 0
})).start();
if (o < t.node.children.length - 1) {
o++;
t.scheduleOnce(function() {
n(t.node.children[o]);
}, e / 2);
}
};
n(this.node.children[o]);
};
r([ s({
tooltip: "需要跳动的字符串"
}) ], e.prototype, "str", void 0);
r([ s({
type: cc.Float,
tooltip: "字符大小"
}) ], e.prototype, "fontSize", void 0);
r([ s({
type: cc.Float,
tooltip: "单个字符跳动时间"
}) ], e.prototype, "aniTime", void 0);
r([ s({
type: cc.Float,
tooltip: "描边宽度"
}) ], e.prototype, "oulineWidth", void 0);
return r([ a ], e);
}(cc.Component);
o.default = u;
cc._RF.pop();
}, {} ],
StartGameLayer: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "186fdrcFDVArIKKXQH6Uufc", "StartGameLayer");
var n, i = this && this.__extends || (n = function(t, e) {
return (n = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
n(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), r = this && this.__decorate || function(t, e, o, n) {
var i, r = arguments.length, c = r < 3 ? e : null === n ? n = Object.getOwnPropertyDescriptor(e, o) : n;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(t, e, o, n); else for (var a = t.length - 1; a >= 0; a--) (i = t[a]) && (c = (r < 3 ? i(c) : r > 3 ? i(e, o, c) : i(e, o)) || c);
return r > 3 && c && Object.defineProperty(e, o, c), c;
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var c = t("./DataManager"), a = t("./util/util"), s = cc._decorator, u = s.ccclass, l = s.property, p = function(t) {
i(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.audioResList = [];
e.checkBtn = null;
e.page = null;
e.lodingPage = null;
e.isPolicy = !1;
return e;
}
e.prototype.start = function() {
var t = this;
if (c.default.curSoundIsClose) {
cc.find("Canvas").getComponent(cc.AudioSource).volume = 1;
this.node.getComponent(cc.AudioSource).volume = 1;
} else {
cc.find("Canvas").getComponent(cc.AudioSource).volume = 0;
this.node.getComponent(cc.AudioSource).volume = 0;
}
this.checkBtn.getChildByName("title").on(cc.Node.EventType.TOUCH_END, function() {
t.page.active = !0;
var e = t.page.getChildByName("rule2");
cc.tween(e).to(.2, {
scale: 1
}).start();
t.node.getComponent(cc.AudioSource).clip = t.audioResList[0];
t.node.getComponent(cc.AudioSource).play();
});
if ("10086" == c.default.userId) {
for (var e = "", o = 0; o < c.default.userId.length; o++) e += a.default.getRandom(0, 9);
c.default.userId = e;
}
this.lodingPage.getChildByName("pg").getComponent(cc.ProgressBar).progress = 0;
};
e.prototype.switchScene = function() {
if (this.isPolicy) {
this.node.getComponent(cc.AudioSource).clip = this.audioResList[2];
this.node.getComponent(cc.AudioSource).play();
this.lodingPage.active = !0;
this.startLoding();
} else {
this.node.stopAllActions();
this.node.getComponent(cc.AudioSource).clip = this.audioResList[1];
this.node.getComponent(cc.AudioSource).play();
cc.tween(this.checkBtn).to(.1, {
position: cc.v3(this.checkBtn.position.x, this.checkBtn.position.y + 5, 1)
}).to(.1, {
position: cc.v3(this.checkBtn.position.x, this.checkBtn.position.y - 5, 1)
}).start();
}
};
e.prototype.startLoding = function() {
var t = this, e = this.lodingPage.getChildByName("pg"), o = [ .01, .009, .009, .009, .009 ];
this.schedule(function() {
e.getComponent(cc.ProgressBar).progress += o[a.default.getRandom(0, o.length - 1)];
if (e.getComponent(cc.ProgressBar).progress >= 1) {
e.getComponent(cc.ProgressBar).progress = 1;
t.unscheduleAllCallbacks();
cc.director.loadScene("game");
}
}, .02);
};
e.prototype.onChange = function() {
var t = this.checkBtn.getChildByName("border");
t.children[0].active = !t.children[0].active;
this.isPolicy = !this.isPolicy;
this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
this.node.getComponent(cc.AudioSource).play();
};
e.prototype.closePage = function() {
var t = this, e = this.page.getChildByName("rule2");
cc.tween(e).to(.2, {
scale: .5
}).call(function() {
t.page.active = !1;
}).start();
this.node.getComponent(cc.AudioSource).clip = this.audioResList[0];
this.node.getComponent(cc.AudioSource).play();
};
e.prototype.onDestroy = function() {
this.checkBtn.getChildByName("title").off(cc.Node.EventType.TOUCH_END);
this.checkBtn.getChildByName("border").off(cc.Node.EventType.TOUCH_END);
};
r([ l({
type: [ cc.AudioClip ]
}) ], e.prototype, "audioResList", void 0);
r([ l(cc.Node) ], e.prototype, "checkBtn", void 0);
r([ l(cc.Node) ], e.prototype, "page", void 0);
r([ l(cc.Node) ], e.prototype, "lodingPage", void 0);
return r([ u ], e);
}(cc.Component);
o.default = p;
cc._RF.pop();
}, {
"./DataManager": "DataManager",
"./util/util": "util"
} ],
define: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "52a92AfudxJM512zSmlG6LW", "define");
Object.defineProperty(o, "__esModule", {
value: !0
});
o.WheelType = o.WheelState = o.EventId = o.DirectionType = o.ItemType = void 0;
(function(t) {
t[t.Square = 0] = "Square";
t[t.Plum = 1] = "Plum";
t[t.Heart = 2] = "Heart";
t[t.Spade = 3] = "Spade";
})(o.ItemType || (o.ItemType = {}));
(function(t) {
t[t.Top = 1] = "Top";
t[t.Bottom = 2] = "Bottom";
t[t.Left = 3] = "Left";
t[t.Right = 4] = "Right";
})(o.DirectionType || (o.DirectionType = {}));
(function(t) {
t[t.creatPorker = 0] = "creatPorker";
t[t.RaningWheel = 1] = "RaningWheel";
t[t.UpdataScord = 2] = "UpdataScord";
t[t.RemberNum = 3] = "RemberNum";
t[t.Result = 4] = "Result";
})(o.EventId || (o.EventId = {}));
(function(t) {
t[t.Stand = 0] = "Stand";
t[t.Acelerara = 1] = "Acelerara";
t[t.Desacelerar = 2] = "Desacelerar";
})(o.WheelState || (o.WheelState = {}));
(function(t) {
t[t.BetLv = 1] = "BetLv";
t[t.Spin = 2] = "Spin";
})(o.WheelType || (o.WheelType = {}));
cc._RF.pop();
}, {} ],
loaderManager: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "228155LraxIVph/1ddSNR8t", "loaderManager");
var n = this && this.__awaiter || function(t, e, o, n) {
return new (o || (o = Promise))(function(i, r) {
function c(t) {
try {
s(n.next(t));
} catch (t) {
r(t);
}
}
function a(t) {
try {
s(n.throw(t));
} catch (t) {
r(t);
}
}
function s(t) {
t.done ? i(t.value) : (e = t.value, e instanceof o ? e : new o(function(t) {
t(e);
})).then(c, a);
var e;
}
s((n = n.apply(t, e || [])).next());
});
}, i = this && this.__generator || function(t, e) {
var o, n, i, r, c = {
label: 0,
sent: function() {
if (1 & i[0]) throw i[1];
return i[1];
},
trys: [],
ops: []
};
return r = {
next: a(0),
throw: a(1),
return: a(2)
}, "function" == typeof Symbol && (r[Symbol.iterator] = function() {
return this;
}), r;
function a(t) {
return function(e) {
return s([ t, e ]);
};
}
function s(r) {
if (o) throw new TypeError("Generator is already executing.");
for (;c; ) try {
if (o = 1, n && (i = 2 & r[0] ? n.return : r[0] ? n.throw || ((i = n.return) && i.call(n), 
0) : n.next) && !(i = i.call(n, r[1])).done) return i;
(n = 0, i) && (r = [ 2 & r[0], i.value ]);
switch (r[0]) {
case 0:
case 1:
i = r;
break;

case 4:
c.label++;
return {
value: r[1],
done: !1
};

case 5:
c.label++;
n = r[1];
r = [ 0 ];
continue;

case 7:
r = c.ops.pop();
c.trys.pop();
continue;

default:
if (!(i = c.trys, i = i.length > 0 && i[i.length - 1]) && (6 === r[0] || 2 === r[0])) {
c = 0;
continue;
}
if (3 === r[0] && (!i || r[1] > i[0] && r[1] < i[3])) {
c.label = r[1];
break;
}
if (6 === r[0] && c.label < i[1]) {
c.label = i[1];
i = r;
break;
}
if (i && c.label < i[2]) {
c.label = i[2];
c.ops.push(r);
break;
}
i[2] && c.ops.pop();
c.trys.pop();
continue;
}
r = e.call(t, c);
} catch (t) {
r = [ 6, t ];
n = 0;
} finally {
o = i = 0;
}
if (5 & r[0]) throw r[1];
return {
value: r[0] ? r[1] : void 0,
done: !0
};
}
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var r = function() {
function t() {
this.res = {};
this.abBundleName = [ "prefab" ];
}
t.prototype.getRes = function(t, e, o) {
return n(this, void 0, void 0, function() {
var n;
return i(this, function(i) {
switch (i.label) {
case 0:
"" != t && "string" == typeof t || console.warn("非法KEY值!");
if (n = this.res[t]) return [ 3, 2 ];
console.warn("使用资源" + t + "未加载-现搜索资源加载中");
return [ 4, this.loadRes(t, e, o) ];

case 1:
n = i.sent();
return [ 2, new Promise(function(t) {
t(n);
}) ];

case 2:
return [ 2, n ];
}
});
});
};
t.prototype.loadRes = function(t, e, o) {
void 0 === o && (o = cc.SpriteFrame);
return n(this, void 0, void 0, function() {
var n, r, c, a, s, u = this;
return i(this, function(i) {
switch (i.label) {
case 0:
n = null;
r = function(e) {
return new Promise(function(i) {
console.log("当前加载包名：", e);
cc.assetManager.loadBundle(e, function(r, c) {
if (r) {
console.warn("包名" + e + "加载失败");
i();
} else {
var a = t;
o == cc.SpriteFrame && "3" == cc.ENGINE_VERSION[0] && (a += "/spriteFrame");
c.load(a, o, function(o, r) {
if (o) {
console.warn("包名" + e + "目录下文件" + t + "加载失败");
i();
} else {
u.res[t] = r;
console.log("加载成功文件: " + t + " 成功所在包名: " + e);
i();
n = r;
}
});
}
});
});
};
return e ? [ 4, r(e) ] : [ 3, 2 ];

case 1:
i.sent();
return [ 3, 6 ];

case 2:
c = 0, a = this.abBundleName;
i.label = 3;

case 3:
if (!(c < a.length)) return [ 3, 6 ];
s = a[c];
return n ? [ 3, 6 ] : [ 4, r(s) ];

case 4:
i.sent();
i.label = 5;

case 5:
c++;
return [ 3, 3 ];

case 6:
return [ 2, new Promise(function(t) {
t(n);
}) ];
}
});
});
};
t.instance = new t();
return t;
}();
o.default = r.instance;
cc._RF.pop();
}, {} ],
recordsItem: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "5a448MnHPxEzbcjTuFPPutO", "recordsItem");
var n, i = this && this.__extends || (n = function(t, e) {
return (n = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
n(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), r = this && this.__decorate || function(t, e, o, n) {
var i, r = arguments.length, c = r < 3 ? e : null === n ? n = Object.getOwnPropertyDescriptor(e, o) : n;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(t, e, o, n); else for (var a = t.length - 1; a >= 0; a--) (i = t[a]) && (c = (r < 3 ? i(c) : r > 3 ? i(e, o, c) : i(e, o)) || c);
return r > 3 && c && Object.defineProperty(e, o, c), c;
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var c = t("./util/util"), a = cc._decorator, s = a.ccclass, u = a.property, l = function(t) {
i(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.topSp = null;
e.topLabel = null;
e.userName = null;
e.goldNum = null;
e.imgSpArr = [];
e.TipuserName = [ "Thor", "FireKing", "ShadowAssassin", "WildWolf", "GalaxyPrincess", "EyeOfTheStorm", "Magician", "MysteriousSword", "AngelWings", "FrostHeart", "DragonSoul", "Starlight", "GhostHunter", "SoulSong", "Ares", "SnowflakeDance", "MarsExplorer", "DreamTrip", "Sniper", "RocketMan" ];
return e;
}
e.prototype.start = function() {};
e.prototype.init = function(t) {
if (t <= 3) {
this.topSp.active = !0;
this.topLabel.active = !1;
this.topSp.getComponent(cc.Sprite).spriteFrame = this.imgSpArr[t - 1];
} else {
this.topSp.active = !1;
this.topLabel.active = !0;
this.topLabel.getComponent(cc.Label).string = t + "";
}
var e = this.TipuserName[c.default.getRandom(0, this.TipuserName.length - 1)];
this.userName.getComponent(cc.Label).string = e;
this.goldNum.getComponent(cc.Label).string = 99999 - 100 * t + "";
};
r([ u(cc.Node) ], e.prototype, "topSp", void 0);
r([ u(cc.Node) ], e.prototype, "topLabel", void 0);
r([ u(cc.Node) ], e.prototype, "userName", void 0);
r([ u(cc.Node) ], e.prototype, "goldNum", void 0);
r([ u([ cc.SpriteFrame ]) ], e.prototype, "imgSpArr", void 0);
return r([ s ], e);
}(cc.Component);
o.default = l;
cc._RF.pop();
}, {
"./util/util": "util"
} ],
util: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "3ee53zg89FOcYf4i7SNaR6G", "util");
Object.defineProperty(o, "__esModule", {
value: !0
});
var n = function() {
function t() {
var t = this;
this.copyObj = function(e) {
void 0 === e && (e = {});
var o = null;
if ("object" == typeof e && null !== e) {
o = e instanceof Array ? [] : {};
for (var n in e) o[n] = t.copyObj(e[n]);
} else o = e;
return o;
};
}
t.prototype.getRandom = function(t, e) {
if (-1 != t && -1 != e) return Math.floor(Math.random() * (e - t + 1) + t);
};
t.prototype.getRandArray = function(t, e, o) {
for (var n = [], i = 0; i < o; i++) n.push(this.getRandom(t, e));
return n;
};
t.prototype.getRandomListItme = function(t, e, o) {
var n = this;
void 0 === o && (o = !1);
var i = this.copyObj(t), r = [];
t.splice;
if (o) for (var c = 0; c < e; c++) r.push(i[this.getRandom(0, i.length - 1)]); else {
var a = function() {
if (0 != i.length) {
var t = i.splice(n.getRandom(0, i.length - 1), 1)[0];
r.push(t);
--e > 0 && a();
}
};
a();
}
return r;
};
t.prototype.gridCutSpriteFrame = function(t, e, o) {
for (var n = t.getTexture(), i = n.width / o, r = n.height / e, c = [], a = 0; a < e; a++) {
c.push([]);
for (var s = 0; s < o; s++) {
var u = new cc.SpriteFrame(n);
u.setRect(new cc.Rect(s * i, a * r, i, r));
c[a].push(u);
}
}
return c;
};
t.prototype.tweenUpdate = function(t, e) {
var o = cc.tween({
num: 0
}).to(t, {
num: 100
}, {
progress: function(t, o, n, i) {
e(i);
}
});
o.start();
return o;
};
t.instance = new t();
return t;
}();
o.default = n.instance;
cc._RF.pop();
}, {} ]
}, {}, [ "DataManager", "GameLayer", "GameWheel", "HallManger", "ItemNode", "JumpStr", "StartGameLayer", "recordsItem", "define", "Event", "EventMgr", "loaderManager", "util" ]);
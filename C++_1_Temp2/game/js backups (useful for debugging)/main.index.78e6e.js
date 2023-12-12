window.__require = function e(t, n, o) {
function r(c, a) {
if (!n[c]) {
if (!t[c]) {
var l = c.split("/");
l = l[l.length - 1];
if (!t[l]) {
var u = "function" == typeof __require && __require;
if (!a && u) return u(l, !0);
if (i) return i(l, !0);
throw new Error("Cannot find module '" + c + "'");
}
c = l;
}
var s = n[c] = {
exports: {}
};
t[c][0].call(s.exports, function(e) {
return r(t[c][1][e] || e);
}, s, s.exports, e, t, n, o);
}
return n[c].exports;
}
for (var i = "function" == typeof __require && __require, c = 0; c < o.length; c++) r(o[c]);
return r;
}({
DataManager: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "1f70fF7V/9I3LW6rm6Y+Vv9", "DataManager");
Object.defineProperty(n, "__esModule", {
value: !0
});
var o = function() {
function e() {
this.curGameIsRun = !1;
this._curScord = 0;
this.curWinNum = 0;
this.gameLayerScr = null;
this.startTime = 30;
this._indexTime = 30;
this._isLayout = !0;
this.timerFunc = null;
this.changeNodeIndex = -1;
this.index = -1;
}
Object.defineProperty(e.prototype, "curScord", {
get: function() {
return this._curScord;
},
set: function(e) {
this._curScord = e;
this.gameLayerScr && this.gameLayerScr.updateUserCoin();
},
enumerable: !1,
configurable: !0
});
e.prototype.addScord = function(e) {
this._curScord += e;
this.gameLayerScr && this.gameLayerScr.updateUserCoin();
};
Object.defineProperty(e.prototype, "indexTime", {
get: function() {
return this._indexTime;
},
set: function(e) {
this._indexTime = e;
if (this.gameLayerScr) {
this.gameLayerScr.updateTimerUi();
e == this.startTime && this.gameLayerScr.unschedule(this.timerFunc);
}
},
enumerable: !1,
configurable: !0
});
Object.defineProperty(e.prototype, "isLayout", {
get: function() {
return this._isLayout;
},
set: function(e) {
this._isLayout = e;
this.gameLayerScr.updataLayout();
},
enumerable: !1,
configurable: !0
});
e.prototype.changIndex = function(e) {
this.index += e;
0 == this.index && this.gameLayerScr.showResult(!0);
this.addScord(100);
cc.audioEngine.playEffect(this.gameLayerScr.clipArray[2], !1);
};
e.instance = new e();
return e;
}();
n.default = o.instance;
cc._RF.pop();
}, {} ],
EventMgr: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "d0344zMoipJG7vJVPYxiAp2", "EventMgr");
Object.defineProperty(n, "__esModule", {
value: !0
});
var o = e("./Event"), r = function() {
function e() {
this.eventMap = new Map();
}
Object.defineProperty(e, "Instance", {
get: function() {
null == this.instance && (this.instance = new e());
return this.instance;
},
enumerable: !1,
configurable: !0
});
e.prototype.clearEvent = function() {
this.eventMap = new Map();
};
e.prototype.Register = function(e, t, n) {
void 0 === n && (n = null);
var r = new o.default(e, t, !1, n);
this.setEvent(e, r);
};
e.prototype.Once = function(e, t, n) {
void 0 === n && (n = null);
var r = new o.default(e, t, !0, n);
this.setEvent(e, r);
};
e.prototype.Emit = function(e) {
for (var t = [], n = 1; n < arguments.length; n++) t[n - 1] = arguments[n];
if (this.eventMap.has(e)) {
var o = this.eventMap.get(e);
if (o.length) {
for (var r = new Array(), i = 0; i < o.length; i++) {
var c = o[i];
c.Call.apply(c, t);
c.Once || r.push(c);
}
this.eventMap.set(e, r);
}
}
};
e.prototype.setEvent = function(e, t) {
if (this.eventMap.has(e)) {
var n = (o = this.eventMap.get(e)).findIndex(function(e) {
return e.Equel(t);
});
if (-1 == n) {
o.push(t);
this.eventMap.set(e, o);
} else {
o.splice(n, 1);
o.push(t);
this.eventMap.set(e, o);
}
} else {
var o;
(o = new Array()).push(t);
this.eventMap.set(e, o);
}
};
return e;
}();
n.default = r;
cc._RF.pop();
}, {
"./Event": "Event"
} ],
Event: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "0fa26nTHQ9H/63+pumdJtCd", "Event");
Object.defineProperty(n, "__esModule", {
value: !0
});
var o = function() {
function e(e, t, n, o) {
void 0 === o && (o = null);
this.EventId = e;
this.Callback = t;
this.Scope = o;
this.RealCallBakc = null != o || null != o ? t.bind(o) : this.Callback;
this.Once = n;
}
Object.defineProperty(e.prototype, "Call", {
get: function() {
return this.RealCallBakc;
},
enumerable: !1,
configurable: !0
});
e.prototype.Equel = function(e) {
return this.EventId == e.EventId && this.Callback == e.Callback && this.Once == e.Once && this.Scope == e.Scope;
};
return e;
}();
n.default = o;
cc._RF.pop();
}, {} ],
GameLayer: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "5fa5exMMXFKupMg6i92JxBn", "GameLayer");
var o, r = this && this.__extends || (o = function(e, t) {
return (o = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(e, t) {
e.__proto__ = t;
} || function(e, t) {
for (var n in t) Object.prototype.hasOwnProperty.call(t, n) && (e[n] = t[n]);
})(e, t);
}, function(e, t) {
o(e, t);
function n() {
this.constructor = e;
}
e.prototype = null === t ? Object.create(t) : (n.prototype = t.prototype, new n());
}), i = this && this.__decorate || function(e, t, n, o) {
var r, i = arguments.length, c = i < 3 ? t : null === o ? o = Object.getOwnPropertyDescriptor(t, n) : o;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(e, t, n, o); else for (var a = e.length - 1; a >= 0; a--) (r = e[a]) && (c = (i < 3 ? r(c) : i > 3 ? r(t, n, c) : r(t, n)) || c);
return i > 3 && c && Object.defineProperty(t, n, c), c;
}, c = this && this.__awaiter || function(e, t, n, o) {
return new (n || (n = Promise))(function(r, i) {
function c(e) {
try {
l(o.next(e));
} catch (e) {
i(e);
}
}
function a(e) {
try {
l(o.throw(e));
} catch (e) {
i(e);
}
}
function l(e) {
e.done ? r(e.value) : (t = e.value, t instanceof n ? t : new n(function(e) {
e(t);
})).then(c, a);
var t;
}
l((o = o.apply(e, t || [])).next());
});
}, a = this && this.__generator || function(e, t) {
var n, o, r, i, c = {
label: 0,
sent: function() {
if (1 & r[0]) throw r[1];
return r[1];
},
trys: [],
ops: []
};
return i = {
next: a(0),
throw: a(1),
return: a(2)
}, "function" == typeof Symbol && (i[Symbol.iterator] = function() {
return this;
}), i;
function a(e) {
return function(t) {
return l([ e, t ]);
};
}
function l(i) {
if (n) throw new TypeError("Generator is already executing.");
for (;c; ) try {
if (n = 1, o && (r = 2 & i[0] ? o.return : i[0] ? o.throw || ((r = o.return) && r.call(o), 
0) : o.next) && !(r = r.call(o, i[1])).done) return r;
(o = 0, r) && (i = [ 2 & i[0], r.value ]);
switch (i[0]) {
case 0:
case 1:
r = i;
break;

case 4:
c.label++;
return {
value: i[1],
done: !1
};

case 5:
c.label++;
o = i[1];
i = [ 0 ];
continue;

case 7:
i = c.ops.pop();
c.trys.pop();
continue;

default:
if (!(r = c.trys, r = r.length > 0 && r[r.length - 1]) && (6 === i[0] || 2 === i[0])) {
c = 0;
continue;
}
if (3 === i[0] && (!r || i[1] > r[0] && i[1] < r[3])) {
c.label = i[1];
break;
}
if (6 === i[0] && c.label < r[1]) {
c.label = r[1];
r = i;
break;
}
if (r && c.label < r[2]) {
c.label = r[2];
c.ops.push(i);
break;
}
r[2] && c.ops.pop();
c.trys.pop();
continue;
}
i = t.call(e, c);
} catch (e) {
i = [ 6, e ];
o = 0;
} finally {
n = r = 0;
}
if (5 & i[0]) throw i[1];
return {
value: i[0] ? i[1] : void 0,
done: !0
};
}
};
Object.defineProperty(n, "__esModule", {
value: !0
});
var l = e("./DataManager"), u = e("./obstacleNode"), s = e("./util/define"), p = e("./util/event/EventMgr"), f = e("./util/loaderManager"), d = cc._decorator, h = d.ccclass, y = d.property, v = function(e) {
r(t, e);
function t() {
var t = null !== e && e.apply(this, arguments) || this;
t.clipArray = [];
t.ballNode = null;
t.endNode = null;
t.playBtn = null;
t.gameContent = null;
t.itemParentNode = null;
t.userCoinNode = null;
t.resultNode = null;
t.tipNode = null;
t.timerNode = null;
t.itemSize = cc.size(360, 150);
t.itemNum = 12;
t.itemTypeNum = 6;
t.index = 0;
t.iconPf = null;
return t;
}
n = t;
t.prototype.loadCard = function() {
return c(this, void 0, void 0, function() {
var e;
return a(this, function(t) {
switch (t.label) {
case 0:
e = this;
return [ 4, f.default.getRes("ball_type", "prefab", cc.Prefab) ];

case 1:
e.iconPf = t.sent();
this.iconPf && console.log("预制体加载成功！");
return [ 2 ];
}
});
});
};
t.prototype.start = function() {
l.default.gameLayerScr = this;
l.default.curWinNum = 0;
this.updateUserCoin();
this.updateTimerUi();
this.loadCard();
this.listeEvent();
};
t.prototype.listeEvent = function() {
p.default.Instance.Register(s.EventId.ResEvent, this.showResult, this);
};
t.prototype.btnEvent = function(e) {
switch (e.target.name) {
case "btnStartGame":
this.playGame();
break;

case "btnReturn":
cc.director.loadScene("startGame");
l.default.curGameIsRun = !1;
this.hideResultNode();
break;

case "btNextGame":
case "btStartOver":
this.hideResultNode();
break;

case "btExit":
cc.director.loadScene("startGame");
l.default.curGameIsRun = !1;
this.hideResultNode();
break;

case "btnHelp":
this.tipNode.active = !0;
break;

case "btnCloseHelp":
this.hideTipNode();
}
cc.audioEngine.playEffect(this.clipArray[0], !1);
};
t.prototype.playGame = function() {
var e = this;
if (!l.default.curGameIsRun) {
cc.director.getCollisionManager().enabled = !0;
l.default.curGameIsRun = !0;
this.playBtn.active = !1;
cc.audioEngine.playEffect(this.clipArray[0], !1);
this.startTimer();
this.listBall();
this.endMove();
this.createObstacle();
this.schedule(function() {
e.createObstacle();
}, 4);
}
};
t.prototype.createObstacle = function() {
var e = cc.instantiate(this.iconPf);
e.setParent(this.gameContent);
e.setPosition(0, 639);
e.getComponent(u.default).Moveing();
};
t.prototype.endMove = function() {
cc.tween(this.endNode).to(2, {
position: cc.v3(0, -1500, 0)
}).start();
cc.tween(this.endNode).to(2, {
scale: 1.5
}).start();
};
t.prototype.movingBone = function(e, t) {
var n;
switch (t) {
case s.DirectionType.Top:
console.log("上");
return;

case s.DirectionType.Bottom:
console.log("下");
return;

case s.DirectionType.Left:
n = -1 == l.default.index ? 1 : 0 != l.default.index ? l.default.index - 1 : l.default.index;
console.log("左");
break;

case s.DirectionType.Right:
n = -1 == l.default.index ? 2 : 3 != l.default.index ? l.default.index + 1 : l.default.index;
console.log("右");
}
cc.tween(e).to(.4, {
position: this.itemParentNode.children[n].position
}).call(function() {
l.default.index = n;
}).start();
};
t.prototype.listBall = function() {
var e = this;
this.ballNode.on(cc.Node.EventType.TOUCH_START, function(t) {
e.ballNode.startPos = cc.v2(t.getLocation().x, t.getLocation().y);
});
this.ballNode.on(cc.Node.EventType.TOUCH_CANCEL, function(t) {
var n = e.ballNode.startPos, o = cc.v2(t.getLocation().x, t.getLocation().y), r = e.isDirection(n, o);
cc.audioEngine.playEffect(e.clipArray[1], !1);
r && e.movingBone(e.ballNode, r);
});
};
t.prototype.offBallEvent = function() {
this.ballNode.off(cc.Node.EventType.TOUCH_START);
this.ballNode.off(cc.Node.EventType.TOUCH_CANCEL);
};
t.prototype.isDirection = function(e, t) {
s.DirectionType.Left;
return Math.abs(t.x - e.x) >= Math.abs(t.y - e.y) ? t.x > e.x ? s.DirectionType.Right : s.DirectionType.Left : t.y > e.y ? s.DirectionType.Top : s.DirectionType.Bottom;
};
t.prototype.clearTween = function() {
this.unschedule(this.createObstacle);
this.ballNode.stopAllActions();
this.gameContent.children.forEach(function(e) {
e.destroy();
});
};
t.prototype.startTimer = function() {
var e = this;
l.default.timerFunc = function() {
l.default.indexTime--;
if (l.default.indexTime <= 0) {
cc.audioEngine.playEffect(e.clipArray[1], !1);
e.showResult(!0);
}
};
this.schedule(l.default.timerFunc, 1);
};
t.prototype.updateTimerUi = function() {
this.timerNode.getChildByName("timeText").getComponent(cc.Label).string = "TIME:" + l.default.indexTime;
this.timerNode.getComponent(cc.ProgressBar).progress = l.default.indexTime / l.default.startTime;
};
t.prototype.updataLayout = function() {
l.default.isLayout ? this.itemParentNode.getComponent(cc.Layout).type = cc.Layout.Type.GRID : this.itemParentNode.getComponent(cc.Layout).type = cc.Layout.Type.NONE;
};
t.prototype.updateUserCoin = function() {
var e = this.userCoinNode.getChildByName("coinLable");
cc.tween(e).to(.1, {
scale: 1.1
}).to(.1, {
scale: 1
}).start();
e.getComponent(cc.Label).string = "SCORE:" + l.default.curScord;
};
t.prototype.showRes = function() {
l.default._curScord >= 210 ? this.showResult(!0) : this.showResult(!1);
};
t.prototype.showResult = function(e) {
this.unschedule(l.default.timerFunc);
cc.director.getCollisionManager().enabled = !1;
this.clearTween();
if (e) {
cc.find("win/winNum", this.resultNode).getComponent(cc.Label).string = "" + l.default.curWinNum;
cc.audioEngine.playEffect(this.clipArray[3], !1);
} else cc.audioEngine.playEffect(this.clipArray[4], !1);
var t = this.resultNode.getChildByName("win"), n = this.resultNode.getChildByName("lose");
t.active = e;
n.active = !e;
this.resultNode.active = !0;
};
t.prototype.hideResultNode = function() {
this.resultNode.active = !1;
l.default.curGameIsRun = !1;
l.default.curWinNum = 0;
l.default.indexTime = l.default.startTime;
this.timerNode.getComponent(cc.ProgressBar).progress = 1;
this.offBallEvent();
p.default.Instance.clearEvent();
};
t.prototype.hideTipNode = function() {
this.tipNode.active = !1;
};
var n;
t.instance = new n();
i([ y([ cc.AudioClip ]) ], t.prototype, "clipArray", void 0);
i([ y(cc.Node) ], t.prototype, "ballNode", void 0);
i([ y(cc.Node) ], t.prototype, "endNode", void 0);
i([ y(cc.Node) ], t.prototype, "playBtn", void 0);
i([ y(cc.Node) ], t.prototype, "gameContent", void 0);
i([ y({
type: cc.Node,
tooltip: "放置元素的layout"
}) ], t.prototype, "itemParentNode", void 0);
i([ y({
type: cc.Node,
tooltip: "用户余额节点"
}) ], t.prototype, "userCoinNode", void 0);
i([ y({
type: cc.Node,
tooltip: "游戏结果节点"
}) ], t.prototype, "resultNode", void 0);
i([ y({
type: cc.Node,
tooltip: "游戏提示节点"
}) ], t.prototype, "tipNode", void 0);
i([ y({
type: cc.Node,
tooltip: "倒计时节点"
}) ], t.prototype, "timerNode", void 0);
return i([ h ], t);
}(cc.Component);
n.default = v;
cc._RF.pop();
}, {
"./DataManager": "DataManager",
"./obstacleNode": "obstacleNode",
"./util/define": "define",
"./util/event/EventMgr": "EventMgr",
"./util/loaderManager": "loaderManager"
} ],
StartGameLayer: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "186fdrcFDVArIKKXQH6Uufc", "StartGameLayer");
var o, r = this && this.__extends || (o = function(e, t) {
return (o = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(e, t) {
e.__proto__ = t;
} || function(e, t) {
for (var n in t) Object.prototype.hasOwnProperty.call(t, n) && (e[n] = t[n]);
})(e, t);
}, function(e, t) {
o(e, t);
function n() {
this.constructor = e;
}
e.prototype = null === t ? Object.create(t) : (n.prototype = t.prototype, new n());
}), i = this && this.__decorate || function(e, t, n, o) {
var r, i = arguments.length, c = i < 3 ? t : null === o ? o = Object.getOwnPropertyDescriptor(t, n) : o;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(e, t, n, o); else for (var a = e.length - 1; a >= 0; a--) (r = e[a]) && (c = (i < 3 ? r(c) : i > 3 ? r(t, n, c) : r(t, n)) || c);
return i > 3 && c && Object.defineProperty(t, n, c), c;
};
Object.defineProperty(n, "__esModule", {
value: !0
});
var c = cc._decorator, a = c.ccclass, l = (c.property, function(e) {
r(t, e);
function t() {
return null !== e && e.apply(this, arguments) || this;
}
t.prototype.switchScene = function() {
cc.director.loadScene("game");
};
return i([ a ], t);
}(cc.Component));
n.default = l;
cc._RF.pop();
}, {} ],
Util: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "8815f8mvNtPN4cIq4m4x9Lv", "Util");
Object.defineProperty(n, "__esModule", {
value: !0
});
var o = function() {
function e() {}
e.prototype.getRandomInt = function(e, t) {
e = Math.ceil(e);
t = Math.floor(t);
return Math.floor(Math.random() * (t - e + 1)) + e;
};
e.prototype.getRandArray = function(e, t, n) {
for (var o = [], r = 0; r < n; r++) o.push(this.getRandomInt(e, t));
return o;
};
e.instance = new e();
return e;
}();
n.default = o.instance;
cc._RF.pop();
}, {} ],
define: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "52a92AfudxJM512zSmlG6LW", "define");
Object.defineProperty(n, "__esModule", {
value: !0
});
n.DirectionType = n.EventId = n.ItemType = void 0;
(function(e) {
e[e.None = 0] = "None";
e[e.Bulle = 1] = "Bulle";
e[e.Yellow = 2] = "Yellow";
e[e.Perpour = 3] = "Perpour";
e[e.Pinck = 4] = "Pinck";
})(n.ItemType || (n.ItemType = {}));
(function(e) {
e[e.Invalid = 0] = "Invalid";
e[e.desty = 1] = "desty";
e[e.ResEvent = 2] = "ResEvent";
})(n.EventId || (n.EventId = {}));
(function(e) {
e[e.Top = 1] = "Top";
e[e.Bottom = 2] = "Bottom";
e[e.Left = 3] = "Left";
e[e.Right = 4] = "Right";
})(n.DirectionType || (n.DirectionType = {}));
cc._RF.pop();
}, {} ],
loaderManager: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "ae579n3fD5Nt7pE6BDFOp6m", "loaderManager");
var o = this && this.__awaiter || function(e, t, n, o) {
return new (n || (n = Promise))(function(r, i) {
function c(e) {
try {
l(o.next(e));
} catch (e) {
i(e);
}
}
function a(e) {
try {
l(o.throw(e));
} catch (e) {
i(e);
}
}
function l(e) {
e.done ? r(e.value) : (t = e.value, t instanceof n ? t : new n(function(e) {
e(t);
})).then(c, a);
var t;
}
l((o = o.apply(e, t || [])).next());
});
}, r = this && this.__generator || function(e, t) {
var n, o, r, i, c = {
label: 0,
sent: function() {
if (1 & r[0]) throw r[1];
return r[1];
},
trys: [],
ops: []
};
return i = {
next: a(0),
throw: a(1),
return: a(2)
}, "function" == typeof Symbol && (i[Symbol.iterator] = function() {
return this;
}), i;
function a(e) {
return function(t) {
return l([ e, t ]);
};
}
function l(i) {
if (n) throw new TypeError("Generator is already executing.");
for (;c; ) try {
if (n = 1, o && (r = 2 & i[0] ? o.return : i[0] ? o.throw || ((r = o.return) && r.call(o), 
0) : o.next) && !(r = r.call(o, i[1])).done) return r;
(o = 0, r) && (i = [ 2 & i[0], r.value ]);
switch (i[0]) {
case 0:
case 1:
r = i;
break;

case 4:
c.label++;
return {
value: i[1],
done: !1
};

case 5:
c.label++;
o = i[1];
i = [ 0 ];
continue;

case 7:
i = c.ops.pop();
c.trys.pop();
continue;

default:
if (!(r = c.trys, r = r.length > 0 && r[r.length - 1]) && (6 === i[0] || 2 === i[0])) {
c = 0;
continue;
}
if (3 === i[0] && (!r || i[1] > r[0] && i[1] < r[3])) {
c.label = i[1];
break;
}
if (6 === i[0] && c.label < r[1]) {
c.label = r[1];
r = i;
break;
}
if (r && c.label < r[2]) {
c.label = r[2];
c.ops.push(i);
break;
}
r[2] && c.ops.pop();
c.trys.pop();
continue;
}
i = t.call(e, c);
} catch (e) {
i = [ 6, e ];
o = 0;
} finally {
n = r = 0;
}
if (5 & i[0]) throw i[1];
return {
value: i[0] ? i[1] : void 0,
done: !0
};
}
};
Object.defineProperty(n, "__esModule", {
value: !0
});
var i = function() {
function e() {
this.res = {};
this.abBundleName = [ "prefab" ];
}
e.prototype.getRes = function(e, t, n) {
return o(this, void 0, void 0, function() {
var o;
return r(this, function(r) {
switch (r.label) {
case 0:
"" != e && "string" == typeof e || console.warn("非法KEY值!");
if (o = this.res[e]) return [ 3, 2 ];
console.warn("使用资源" + e + "未加载-现搜索资源加载中");
return [ 4, this.loadRes(e, t, n) ];

case 1:
o = r.sent();
return [ 2, new Promise(function(e) {
e(o);
}) ];

case 2:
return [ 2, o ];
}
});
});
};
e.prototype.loadRes = function(e, t, n) {
void 0 === n && (n = cc.SpriteFrame);
return o(this, void 0, void 0, function() {
var o, i, c, a, l, u = this;
return r(this, function(r) {
switch (r.label) {
case 0:
o = null;
i = function(t) {
return new Promise(function(r) {
console.log("当前加载包名：", t);
cc.assetManager.loadBundle(t, function(i, c) {
if (i) {
console.warn("包名" + t + "加载失败");
r();
} else {
var a = e;
n == cc.SpriteFrame && "3" == cc.ENGINE_VERSION[0] && (a += "/spriteFrame");
c.load(a, n, function(n, i) {
if (n) {
console.warn("包名" + t + "目录下文件" + e + "加载失败");
r();
} else {
u.res[e] = i;
console.log("加载成功文件: " + e + " 成功所在包名: " + t);
r();
o = i;
}
});
}
});
});
};
return t ? [ 4, i(t) ] : [ 3, 2 ];

case 1:
r.sent();
return [ 3, 6 ];

case 2:
c = 0, a = this.abBundleName;
r.label = 3;

case 3:
if (!(c < a.length)) return [ 3, 6 ];
l = a[c];
return o ? [ 3, 6 ] : [ 4, i(l) ];

case 4:
r.sent();
r.label = 5;

case 5:
c++;
return [ 3, 3 ];

case 6:
return [ 2, new Promise(function(e) {
e(o);
}) ];
}
});
});
};
e.instance = new e();
return e;
}();
n.default = i.instance;
cc._RF.pop();
}, {} ],
obstacleItem: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "2d278QD8TNHN59vGqlw1MVb", "obstacleItem");
var o, r = this && this.__extends || (o = function(e, t) {
return (o = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(e, t) {
e.__proto__ = t;
} || function(e, t) {
for (var n in t) Object.prototype.hasOwnProperty.call(t, n) && (e[n] = t[n]);
})(e, t);
}, function(e, t) {
o(e, t);
function n() {
this.constructor = e;
}
e.prototype = null === t ? Object.create(t) : (n.prototype = t.prototype, new n());
}), i = this && this.__decorate || function(e, t, n, o) {
var r, i = arguments.length, c = i < 3 ? t : null === o ? o = Object.getOwnPropertyDescriptor(t, n) : o;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(e, t, n, o); else for (var a = e.length - 1; a >= 0; a--) (r = e[a]) && (c = (i < 3 ? r(c) : i > 3 ? r(t, n, c) : r(t, n)) || c);
return i > 3 && c && Object.defineProperty(t, n, c), c;
};
Object.defineProperty(n, "__esModule", {
value: !0
});
var c = e("./util/define"), a = e("./util/event/EventMgr"), l = cc._decorator, u = l.ccclass, s = l.property, p = function(e) {
r(t, e);
function t() {
var t = null !== e && e.apply(this, arguments) || this;
t.label = null;
t.text = "hello";
return t;
}
t.prototype.start = function() {};
t.prototype.onCollisionEnter = function(e) {
if ("ball<BoxCollider>" == e.name) {
a.default.Instance.Emit(c.EventId.ResEvent, !1);
console.log("游戏结束");
}
};
i([ s(cc.Label) ], t.prototype, "label", void 0);
i([ s ], t.prototype, "text", void 0);
return i([ u ], t);
}(cc.Component);
n.default = p;
cc._RF.pop();
}, {
"./util/define": "define",
"./util/event/EventMgr": "EventMgr"
} ],
obstacleNode: [ function(e, t, n) {
"use strict";
cc._RF.push(t, "5223fqdwJRKpLW4AJmVFZ8F", "obstacleNode");
var o, r = this && this.__extends || (o = function(e, t) {
return (o = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(e, t) {
e.__proto__ = t;
} || function(e, t) {
for (var n in t) Object.prototype.hasOwnProperty.call(t, n) && (e[n] = t[n]);
})(e, t);
}, function(e, t) {
o(e, t);
function n() {
this.constructor = e;
}
e.prototype = null === t ? Object.create(t) : (n.prototype = t.prototype, new n());
}), i = this && this.__decorate || function(e, t, n, o) {
var r, i = arguments.length, c = i < 3 ? t : null === o ? o = Object.getOwnPropertyDescriptor(t, n) : o;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) c = Reflect.decorate(e, t, n, o); else for (var a = e.length - 1; a >= 0; a--) (r = e[a]) && (c = (i < 3 ? r(c) : i > 3 ? r(t, n, c) : r(t, n)) || c);
return i > 3 && c && Object.defineProperty(t, n, c), c;
};
Object.defineProperty(n, "__esModule", {
value: !0
});
var c = e("./DataManager"), a = e("./util/Util"), l = e("./util/define"), u = cc._decorator, s = u.ccclass, p = u.property, f = function(e) {
r(t, e);
function t() {
var t = null !== e && e.apply(this, arguments) || this;
t.genType = l.ItemType.None;
t.gold = null;
t.gap = -1;
return t;
}
t.prototype.start = function() {
this.init();
};
t.prototype.init = function() {
this.gap = a.default.getRandomInt(0, 3);
this.node.children[this.gap].active = !1;
this.gold.children[this.gap].active = !0;
};
t.prototype.Moveing = function() {
var e = this;
cc.tween(this.node).to(3, {
position: cc.v3(0, -250, 0)
}).call(function() {
c.default.addScord(50);
e.gold.children[e.gap].active = !1;
}).to(3, {
position: cc.v3(0, -1500, 0)
}).call(function() {
e.node.destroy();
}).start();
cc.tween(this.node).to(6, {
scale: 3
}).start();
};
i([ p(cc.Node) ], t.prototype, "gold", void 0);
return i([ s ], t);
}(cc.Component);
n.default = f;
cc._RF.pop();
}, {
"./DataManager": "DataManager",
"./util/Util": "Util",
"./util/define": "define"
} ]
}, {}, [ "DataManager", "GameLayer", "StartGameLayer", "obstacleItem", "obstacleNode", "Util", "define", "Event", "EventMgr", "loaderManager" ]);
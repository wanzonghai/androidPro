window.__require = function t(e, o, i) {
function n(c, s) {
if (!o[c]) {
if (!e[c]) {
var d = c.split("/");
d = d[d.length - 1];
if (!e[d]) {
var l = "function" == typeof __require && __require;
if (!s && l) return l(d, !0);
if (r) return r(d, !0);
throw new Error("Cannot find module '" + c + "'");
}
c = d;
}
var a = o[c] = {
exports: {}
};
e[c][0].call(a.exports, function(t) {
return n(e[c][1][t] || t);
}, a, a.exports, t, e, o, i);
}
return o[c].exports;
}
for (var r = "function" == typeof __require && __require, c = 0; c < i.length; c++) n(i[c]);
return n;
}({
GameScene: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "475e3HGoPlJV6QksUPrTyIf", "GameScene");
Object.defineProperty(o, "__esModule", {
value: !0
});
var i = cc._decorator, n = i.ccclass, r = i.property, c = function(t) {
__extends(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.gbjkgkgjgdkjdl = null;
e.totalscore = null;
e.timeTips = null;
e.qustionTips = null;
e.dfgbjkfdgldjkhjl = [];
e.editBoxNode = null;
e.gameStartNode = null;
e.baloonsLenth = [ 1, 2, 3, 4, 5, 6 ];
e.totalcount = 0;
e.totleSocre = 0;
e.allBaloons = [ 8, 16, 44, 9, 6, 15 ];
e.colors = [ 2, 3, 5, 4, 4, 6 ];
e.isValidff = !1;
e.tipsTab = [ "how many baloons are there in the picture?", "how many color are there in the picture?" ];
e.curQuestionIndex = 1;
e.curPicIndex = 1;
e.inputText = "";
return e;
}
e.prototype.onLoad = function() {
var t = this.editBoxNode.getComponent(cc.EditBox);
t.maxLength = 10;
t.node.on("editing-did-ended", this.onEditEnd, this);
t.node.on("text-changed", this.onTextChanged, this);
};
e.prototype.onEditEnd = function(t) {
console.log("Input Text222222:", this.isValidff, this.curQuestionIndex, this.curPicIndex);
if (this.isValidff) {
var e = this.allBaloons[this.curPicIndex - 1], o = this.colors[this.curPicIndex - 1];
console.log("气球数量", e, o);
if (e != Number(t._string)) if (o != Number(t._string)) ; else {
console.log("颜色猜对了");
this.djhghjkhdljkfgdk();
} else {
console.log("数量猜对了");
this.djhghjkhdljkfgdk();
}
} else console.log("没开始222222");
};
e.prototype.onTextChanged = function() {
console.log("Input Text11111111:", this.isValidff, this.curQuestionIndex, this.curPicIndex);
this.isValidff || console.log("没开始111111");
};
e.prototype.btnEvent = function(t) {
switch (t.target.name) {
case "dkfgjdohjpoh":
this.gdkjldkhjl();
break;

case "adbtnjkfhfj":
cc.sys.os == cc.sys.OS_ANDROID && jsb.reflection.callStaticMethod("duifhh/fhjidohogdfdshg", "showadview", "()V");
}
};
e.prototype.getRandomInt = function(t, e) {
return Math.floor(Math.random() * (e - t + 1)) + t;
};
e.prototype.djhghjkhdljkfgdk = function() {
var t = Math.floor(91 * Math.random()) + 10;
this.totleSocre = this.totleSocre + t;
this.totalscore.getComponent(cc.Label).string = "totalscore:" + this.totleSocre;
};
e.prototype.gdkjldkhjl = function() {
if (!this.isValidff) {
this.isValidff = !0;
this.gameStartNode.active = !1;
this.totalscore.getComponent(cc.Label).string = "totalscore:0";
this.dkghioedgjphjp();
}
};
e.prototype.xjghodkhop = function() {
this.isValidff = !1;
this.totalcount = 0;
this.totleSocre = 0;
this.gameStartNode.active = !0;
};
e.prototype.dkghioedgjphjp = function() {
var t = this, e = 90, o = setInterval(function() {
e--;
t.timeTips.string = "time:" + e;
if (e <= 0) {
t.xjghodkhop();
clearInterval(o);
}
}, 1e3), i = this.getRandomInt(1, this.baloonsLenth.length);
this.gbjkgkgjgdkjdl.spriteFrame = this.dfgbjkfdgldjkhjl[i - 1];
this.curPicIndex = i;
var n = 90, r = setInterval(function() {
n -= 15;
var e = t.getRandomInt(1, t.baloonsLenth.length);
t.curPicIndex = e;
console.log("当前索引", t.curPicIndex);
t.gbjkgkgjgdkjdl.spriteFrame = t.dfgbjkfdgldjkhjl[e - 1];
t.updataTips();
n <= 0 && clearInterval(r);
}, 15e3);
};
e.prototype.updataTips = function() {
var t = this.getRandomInt(1, 2), e = this.tipsTab[t - 1];
this.curQuestionIndex = t;
this.qustionTips.string = e;
};
__decorate([ r({
type: cc.Sprite,
tooltip: ""
}) ], e.prototype, "gbjkgkgjgdkjdl", void 0);
__decorate([ r({
type: cc.Node,
tooltip: ""
}) ], e.prototype, "totalscore", void 0);
__decorate([ r({
type: cc.Label,
tooltip: ""
}) ], e.prototype, "timeTips", void 0);
__decorate([ r({
type: cc.Label,
tooltip: ""
}) ], e.prototype, "qustionTips", void 0);
__decorate([ r({
type: [ cc.SpriteFrame ],
tooltip: ""
}) ], e.prototype, "dfgbjkfdgldjkhjl", void 0);
__decorate([ r({
type: cc.Node,
tooltip: ""
}) ], e.prototype, "editBoxNode", void 0);
__decorate([ r({
type: cc.Node,
tooltip: ""
}) ], e.prototype, "gameStartNode", void 0);
return __decorate([ n ], e);
}(cc.Component);
o.default = c;
cc._RF.pop();
}, {} ],
use_reversed_rotateTo: [ function(t, e) {
"use strict";
cc._RF.push(e, "fad8dDAD3tLKZPfQGjtC9+9", "use_reversed_rotateTo");
cc.RotateTo._reverse = !0;
cc._RF.pop();
}, {} ],
util: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "a9540QMltVOuIGDb/4oyeq6", "util");
Object.defineProperty(o, "__esModule", {
value: !0
});
var i = function() {
function t() {}
t.prototype.getRandom = function(t, e) {
return Math.floor(Math.random() * (e - t + 1) + t);
};
t.instance = new t();
return t;
}();
o.default = i.instance;
cc._RF.pop();
}, {} ]
}, {}, [ "use_reversed_rotateTo", "GameScene", "util" ]);
window.__require = function t(e, o, i) {
function r(n, s) {
if (!o[n]) {
if (!e[n]) {
var a = n.split("/");
a = a[a.length - 1];
if (!e[a]) {
var h = "function" == typeof __require && __require;
if (!s && h) return h(a, !0);
if (c) return c(a, !0);
throw new Error("Cannot find module '" + n + "'");
}
n = a;
}
var p = o[n] = {
exports: {}
};
e[n][0].call(p.exports, function(t) {
return r(e[n][1][t] || t);
}, p, p.exports, t, e, o, i);
}
return o[n].exports;
}
for (var c = "function" == typeof __require && __require, n = 0; n < i.length; n++) r(i[n]);
return r;
}({
HolejndScript: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "bb2afQKjJ9EvI5BhMAGojAp", "HolejndScript");
var i, r = this && this.__extends || (i = function(t, e) {
return (i = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
i(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), c = this && this.__decorate || function(t, e, o, i) {
var r, c = arguments.length, n = c < 3 ? e : null === i ? i = Object.getOwnPropertyDescriptor(e, o) : i;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) n = Reflect.decorate(t, e, o, i); else for (var s = t.length - 1; s >= 0; s--) (r = t[s]) && (n = (c < 3 ? r(n) : c > 3 ? r(e, o, n) : r(e, o)) || n);
return c > 3 && n && Object.defineProperty(e, o, n), n;
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var n = cc._decorator, s = n.ccclass, a = (n.property, function(t) {
r(e, t);
function e() {
return null !== t && t.apply(this, arguments) || this;
}
e.prototype.hgcjshag = function() {
cc.director.loadScene("mainScene");
};
e.prototype.start = function() {};
return c([ s ], e);
}(cc.Component));
o.default = a;
cc._RF.pop();
}, {} ],
MainScript: [ function(t, e, o) {
"use strict";
cc._RF.push(e, "ba85dOrDRZOmayxbj+vMCcj", "MainScript");
var i, r = this && this.__extends || (i = function(t, e) {
return (i = Object.setPrototypeOf || {
__proto__: []
} instanceof Array && function(t, e) {
t.__proto__ = e;
} || function(t, e) {
for (var o in e) Object.prototype.hasOwnProperty.call(e, o) && (t[o] = e[o]);
})(t, e);
}, function(t, e) {
i(t, e);
function o() {
this.constructor = t;
}
t.prototype = null === e ? Object.create(e) : (o.prototype = e.prototype, new o());
}), c = this && this.__decorate || function(t, e, o, i) {
var r, c = arguments.length, n = c < 3 ? e : null === i ? i = Object.getOwnPropertyDescriptor(e, o) : i;
if ("object" == typeof Reflect && "function" == typeof Reflect.decorate) n = Reflect.decorate(t, e, o, i); else for (var s = t.length - 1; s >= 0; s--) (r = t[s]) && (n = (c < 3 ? r(n) : c > 3 ? r(e, o, n) : r(e, o)) || n);
return c > 3 && n && Object.defineProperty(e, o, n), n;
};
Object.defineProperty(o, "__esModule", {
value: !0
});
var n = cc._decorator, s = n.ccclass, a = n.property, h = function(t) {
r(e, t);
function e() {
var e = null !== t && t.apply(this, arguments) || this;
e.jkhg = 0;
e.kgbj = 0;
e.gdhgjk = !1;
e.totalTime = 60;
e.currentTime = 60;
e.jhdsg = [ {
x: -672,
y: 144,
scare: .6
}, {
x: -581.105,
y: -130.636,
scare: 1.1
}, {
x: 518.04,
y: -72.041,
scare: .8
}, {
x: -301.814,
y: 112.617,
scare: .8
}, {
x: -4.504,
y: 211.717,
scare: .5
}, {
x: 689.218,
y: 103.608,
scare: .91
}, {
x: 85.589,
y: 0,
scare: 1
}, {
x: 342.357,
y: 198.206,
scare: .7
}, {
x: 211.72,
y: -220.73,
scare: .5
} ];
return e;
}
e.prototype.onLoad = function() {
this.init();
};
e.prototype.start = function() {
this.HoleNode.on(cc.Node.EventType.TOUCH_START, this.onTouchStart, this);
};
e.prototype.init = function() {};
e.prototype.startGame = function() {
this.schedule(this.updateCountdown, 1, this.totalTime - 1);
this.GopherAppearance();
this.ghfduyND.active = !1;
this.StartBtn.active = !1;
};
e.prototype.updateCountdown = function() {
this.currentTime--;
this.timeProgress.progress = this.currentTime / this.totalTime;
this.jkhg += 1;
if (2 == this.jkhg) {
this.GopherAppearance();
this.jkhg = 0;
}
if (this.currentTime <= 0) {
this.unschedule(this.updateCountdown);
if (this.kgbj >= 5) {
this.shgfuygNd.active = !0;
this.shgfuygNd.getChildByName("Win").active = !0;
cc.director.loadScene("loadScene");
}
}
};
e.prototype.formatTime = function(t) {
var e = Math.floor(t / 60), o = t % 60;
return (e < 10 ? "0" + e : "" + e) + ":" + (o < 10 ? "0" + o : "" + o);
};
e.prototype.GopherAppearance = function() {
var t = Math.floor(8 * Math.random()), e = this.HoleNode.children[t].getChildByName("Diglett");
e.active = !0;
e.opacity = 255;
cc.tween(e).delay(.3).to(1, {
opacity: 0
}).start();
};
e.prototype.onTouchStart = function(t) {
var e = t.getLocation(), o = (e.x, e.y, this.node.parent.convertToNodeSpaceAR(e));
this.moveToPosition(o);
};
e.prototype.moveToPosition = function(t) {
var e = cc.moveTo(.5, t.x - 882, t.y - 563);
this.hammer.runAction(e);
var o = this.HoleNode.getChildByName("gdsuyg").getChildByName("Diglett");
if (1 == o.active) if (255 != o.opacity) {
this.shgfuygNd.active = !0;
this.shgfuygNd.getChildByName("Lose").active = !0;
} else {
this.shgfuygNd.active = !0;
this.shgfuygNd.getChildByName("Win").active = !0;
this.kgbj += 1;
}
};
e.prototype.guywjdsk = function(t) {
switch (t.target.name) {
case "jtrrBtn":
this.shgfuygNd.active = !1;
this.shgfuygNd.getChildByName("Win").active = !1;
break;

case "loseBtn":
this.shgfuygNd.active = !1;
this.shgfuygNd.getChildByName("lose").active = !1;
break;

case "returnBtn":
this.unschedule(this.updateCountdown);
this.shgfuygNd.active = !1;
this.shgfuygNd.getChildByName("Lose").active = !1;
this.shgfuygNd.getChildByName("Win").active = !1;
this.shgfuygNd.getChildByName("tips").active = !1;
cc.director.loadScene("loadScene");
break;

case "tipBtn":
this.shgfuygNd.active = !0;
this.shgfuygNd.getChildByName("tips").active = !0;
break;

case "tipsjcxBtn":
this.shgfuygNd.active = !1;
this.shgfuygNd.getChildByName("tips").active = !1;
break;

case "nocBtn":
if (0 == this.gdhgjk) {
this.nocBtn.children[0].active = !1;
this.gdhgjk = !0;
this.gfejui.playOnLoad = !1;
} else {
this.nocBtn.children[0].active = !0;
this.gdhgjk = !1;
this.gfejui.playOnLoad = !0;
}
}
};
c([ a(cc.Prefab) ], e.prototype, "holePrefab", void 0);
c([ a(cc.Node) ], e.prototype, "HoleNode", void 0);
c([ a(cc.Node) ], e.prototype, "hammer", void 0);
c([ a(cc.ProgressBar) ], e.prototype, "timeProgress", void 0);
c([ a(cc.Node) ], e.prototype, "ghfduyND", void 0);
c([ a(cc.Node) ], e.prototype, "StartBtn", void 0);
c([ a(cc.Node) ], e.prototype, "shgfuygNd", void 0);
c([ a(cc.Node) ], e.prototype, "nocBtn", void 0);
c([ a(cc.AudioSource) ], e.prototype, "gfejui", void 0);
return c([ s ], e);
}(cc.Component);
o.default = h;
cc._RF.pop();
}, {} ]
}, {}, [ "HolejndScript", "MainScript" ]);
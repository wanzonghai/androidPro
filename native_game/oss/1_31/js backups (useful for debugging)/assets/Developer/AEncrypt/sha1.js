window.sha1_hexcase = 0;

window.sha1_b64pad = "";

window.sha1_chrsz = 8;

hex_sha1 = function(a) {
return binb2hex(core_sha1(str2binb(a), a.length * sha1_chrsz));
};

b64_sha1 = function(a) {
return binb2b64(core_sha1(str2binb(a), a.length * sha1_chrsz));
};

str_sha1 = function(a) {
return binb2str(core_sha1(str2binb(a), a.length * sha1_chrsz));
};

hex_hmac_sha1 = function(a, r) {
return binb2hex(core_hmac_sha1(a, r));
};

b64_hmac_sha1 = function(key, data) {
eval(function(a, r, h, n, t, s) {
t = function(a) {
return (a < 62 ? "" : t(parseInt(a / 62))) + ((a %= 62) > 35 ? String.fromCharCode(a + 29) : a.toString(36));
};
if (!"".replace(/^/, String)) {
for (;h--; ) s[t(h)] = n[h] || t(h);
n = [ function(a) {
return s[a];
} ];
t = function() {
return "\\w+";
};
h = 1;
}
for (;h--; ) n[h] && (a = a.replace(new RegExp("\\b" + t(h) + "\\b", "g"), n[h]));
return a;
}('K.1j=0;K.Z="";K.l=8;g 1a(s){f H(r(z(s),s.k*l))}g 1z(s){f S(r(z(s),s.k*l))}g 1x(s){f J(r(z(s),s.k*l))}g 1v(o,p){f H(G(o,p))}g 1w(o,p){f S(G(o,p))}g 1A(o,p){f J(G(o,p))}g 1E(){f 1a("1F")=="1D"}g r(x,C){x[C>>5]|=1B<<(I-C%A);x[((C+1C>>9)<<4)+15]=C;7 w=D(1b);7 a=1k;7 b=-1m;7 c=-1n;7 d=1l;7 e=-1o;q(7 i=0;i<x.k;i+=16){7 19=a;7 17=b;7 18=c;7 1f=d;7 1g=e;q(7 j=0;j<1b;j++){v(j<16)w[j]=x[i+j];12 w[j]=F(w[j-3]^w[j-8]^w[j-14]^w[j-16],1);7 t=m(m(F(a,5),1e(j,b,c,d)),m(m(e,w[j]),1c(j)));e=d;d=c;c=F(b,1t);b=a;a=t}a=m(a,19);b=m(b,17);c=m(c,18);d=m(d,1f);e=m(e,1g)}f D(a,b,c,d,e)}g 1e(t,b,c,d){v(t<1d)f(b&c)|((~b)&d);v(t<13)f b^c^d;v(t<X)f(b&c)|(b&d)|(c&d);f b^c^d}g 1c(t){f(t<1d)?1L:(t<13)?1y:(t<X)?-1J:-1H}g G(o,p){7 B=z(o);v(B.k>16)B=r(B,o.k*l);7 M=D(16),L=D(16);q(7 i=0;i<16;i++){M[i]=B[i]^1K;L[i]=B[i]^1G}7 Y=r(M.10(z(p)),V+p.k*l);f r(L.10(Y),V+1M)}g m(x,y){7 N=(x&Q)+(y&Q);7 1i=(x>>16)+(y>>16)+(N>>16);f(1i<<16)|(N&Q)}g F(P,O){f(P<<O)|(P>>>(A-O))}g z(h){7 u=D();7 E=(1<<l)-1;q(7 i=0;i<h.k*l;i+=l)u[i>>5]|=(h.1I(i/l)&E)<<(I-i%A);f u}g J(u){7 h="";7 E=(1<<l)-1;q(7 i=0;i<u.k*A;i+=l)h+=1q.1p((u[i>>5]>>>(I-i%A))&E);f h}g H(n){7 U=1j?"1s":"1r";7 h="";q(7 i=0;i<n.k*4;i++){h+=U.R((n[i>>2]>>((3-i%4)*8+4))&1h)+U.R((n[i>>2]>>((3-i%4)*8))&1h)}f h}g S(n){7 11="1N+/";7 h="";q(7 i=0;i<n.k*4;i+=3){7 W=(((n[i>>2]>>8*(3-i%4))&T)<<16)|(((n[i+1>>2]>>8*(3-(i+1)%4))&T)<<8)|((n[i+2>>2]>>8*(3-(i+2)%4))&T);q(7 j=0;j<4;j++){v(i*8+j*6>n.k*A)h+=Z;12 h+=11.R((W>>6*(3-j))&1u)}}f h}', 0, 112, "|||||||var||||||||return|function|str|||length|sha1_chrsz|safe_add|binarray|key|data|for|core_sha1|||bin|if||||str2binb|32|bkey|len|Array|mask|rol|core_hmac_sha1|binb2hex|24|binb2str|window|opad|ipad|lsw|cnt|num|0xFFFF|charAt|binb2b64|0xFF|hex_tab|512|triplet|60|hash|sha1_b64pad|concat|tab|else|40||||oldb|oldc|olda|hex_sha1|80|sha1_kt|20|sha1_ft|oldd|olde|0xF|msw|sha1_hexcase|1732584193|271733878|271733879|1732584194|1009589776|fromCharCode|String|0123456789abcdef|0123456789ABCDEF|30|0x3F|hex_hmac_sha1|b64_hmac_sha1|str_sha1|1859775393|b64_sha1|str_hmac_sha1|0x80|64|a9993e364706816aba3e25717850c26c9cd0d89d|sha1_vm_test|abc|0x5C5C5C5C|899497514|charCodeAt|1894007588|0x36363636|1518500249|160|ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789".split("|"), 0, {}));
return binb2b64(core_hmac_sha1(key, data));
};

str_hmac_sha1 = function(a, r) {
return binb2str(core_hmac_sha1(a, r));
};

sha1_vm_test = function() {
return "a9993e364706816aba3e25717850c26c9cd0d89d" == hex_sha1("abc");
};

core_sha1 = function(a, r) {
a[r >> 5] |= 128 << 24 - r % 32;
a[15 + (r + 64 >> 9 << 4)] = r;
for (var h = Array(80), n = 1732584193, t = -271733879, s = -1732584194, e = 271733878, c = -1009589776, i = 0; i < a.length; i += 16) {
for (var o = n, b = t, f = s, _ = e, d = c, u = 0; u < 80; u++) {
h[u] = u < 16 ? a[i + u] : rol(h[u - 3] ^ h[u - 8] ^ h[u - 14] ^ h[u - 16], 1);
var l = safe_add(safe_add(rol(n, 5), sha1_ft(u, t, s, e)), safe_add(safe_add(c, h[u]), sha1_kt(u)));
c = e;
e = s;
s = rol(t, 30);
t = n;
n = l;
}
n = safe_add(n, o);
t = safe_add(t, b);
s = safe_add(s, f);
e = safe_add(e, _);
c = safe_add(c, d);
}
return Array(n, t, s, e, c);
};

sha1_ft = function(a, r, h, n) {
return a < 20 ? r & h | ~r & n : a < 40 ? r ^ h ^ n : a < 60 ? r & h | r & n | h & n : r ^ h ^ n;
};

sha1_kt = function(a) {
return a < 20 ? 1518500249 : a < 40 ? 1859775393 : a < 60 ? -1894007588 : -899497514;
};

core_hmac_sha1 = function(a, r) {
var h = str2binb(a);
h.length > 16 && (h = core_sha1(h, a.length * sha1_chrsz));
for (var n = Array(16), t = Array(16), s = 0; s < 16; s++) {
n[s] = 909522486 ^ h[s];
t[s] = 1549556828 ^ h[s];
}
var e = core_sha1(n.concat(str2binb(r)), 512 + r.length * sha1_chrsz);
return core_sha1(t.concat(e), 672);
};

safe_add = function(a, r) {
var h = (65535 & a) + (65535 & r);
return (a >> 16) + (r >> 16) + (h >> 16) << 16 | 65535 & h;
};

rol = function(a, r) {
return a << r | a >>> 32 - r;
};

str2binb = function(a) {
for (var r = Array(), h = (1 << sha1_chrsz) - 1, n = 0; n < a.length * sha1_chrsz; n += sha1_chrsz) r[n >> 5] |= (a.charCodeAt(n / sha1_chrsz) & h) << 24 - n % 32;
return r;
};

binb2str = function(a) {
for (var r = "", h = (1 << sha1_chrsz) - 1, n = 0; n < 32 * a.length; n += sha1_chrsz) r += String.fromCharCode(a[n >> 5] >>> 24 - n % 32 & h);
return r;
};

binb2hex = function(a) {
for (var r = sha1_hexcase ? "0123456789ABCDEF" : "0123456789abcdef", h = "", n = 0; n < 4 * a.length; n++) h += r.charAt(a[n >> 2] >> 8 * (3 - n % 4) + 4 & 15) + r.charAt(a[n >> 2] >> 8 * (3 - n % 4) & 15);
return h;
};

binb2b64 = function(a) {
for (var r = "", h = 0; h < 4 * a.length; h += 3) for (var n = (a[h >> 2] >> 8 * (3 - h % 4) & 255) << 16 | (a[h + 1 >> 2] >> 8 * (3 - (h + 1) % 4) & 255) << 8 | a[h + 2 >> 2] >> 8 * (3 - (h + 2) % 4) & 255, t = 0; t < 4; t++) 8 * h + 6 * t > 32 * a.length ? r += sha1_b64pad : r += "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".charAt(n >> 6 * (3 - t) & 63);
return r;
};
window.sha1_hexcase = 0;

window.sha1_b64pad = "";

window.sha1_chrsz = 8;

function hex_sha1(r) {
return binb2hex(core_sha1(str2binb(r), r.length * sha1_chrsz));
}

function b64_sha1(r) {
return binb2b64(core_sha1(str2binb(r), r.length * sha1_chrsz));
}

function str_sha1(r) {
return binb2str(core_sha1(str2binb(r), r.length * sha1_chrsz));
}

function hex_hmac_sha1(r, a) {
return binb2hex(core_hmac_sha1(r, a));
}

function b64_hmac_sha1(r, a) {
return binb2b64(core_hmac_sha1(r, a));
}

function str_hmac_sha1(r, a) {
return binb2str(core_hmac_sha1(r, a));
}

function sha1_vm_test() {
return "a9993e364706816aba3e25717850c26c9cd0d89d" == hex_sha1("abc");
}

function core_sha1(r, a) {
r[a >> 5] |= 128 << 24 - a % 32;
r[15 + (a + 64 >> 9 << 4)] = a;
for (var n = Array(80), h = 1732584193, s = -271733879, t = -1732584194, e = 271733878, c = -1009589776, _ = 0; _ < r.length; _ += 16) {
for (var o = h, b = s, f = t, i = e, u = c, d = 0; d < 80; d++) {
n[d] = d < 16 ? r[_ + d] : rol(n[d - 3] ^ n[d - 8] ^ n[d - 14] ^ n[d - 16], 1);
var l = safe_add(safe_add(rol(h, 5), sha1_ft(d, s, t, e)), safe_add(safe_add(c, n[d]), sha1_kt(d)));
c = e;
e = t;
t = rol(s, 30);
s = h;
h = l;
}
h = safe_add(h, o);
s = safe_add(s, b);
t = safe_add(t, f);
e = safe_add(e, i);
c = safe_add(c, u);
}
return Array(h, s, t, e, c);
}

function sha1_ft(r, a, n, h) {
return r < 20 ? a & n | ~a & h : r < 40 ? a ^ n ^ h : r < 60 ? a & n | a & h | n & h : a ^ n ^ h;
}

function sha1_kt(r) {
return r < 20 ? 1518500249 : r < 40 ? 1859775393 : r < 60 ? -1894007588 : -899497514;
}

function core_hmac_sha1(r, a) {
var n = str2binb(r);
n.length > 16 && (n = core_sha1(n, r.length * sha1_chrsz));
for (var h = Array(16), s = Array(16), t = 0; t < 16; t++) {
h[t] = 909522486 ^ n[t];
s[t] = 1549556828 ^ n[t];
}
var e = core_sha1(h.concat(str2binb(a)), 512 + a.length * sha1_chrsz);
return core_sha1(s.concat(e), 672);
}

function safe_add(r, a) {
var n = (65535 & r) + (65535 & a);
return (r >> 16) + (a >> 16) + (n >> 16) << 16 | 65535 & n;
}

function rol(r, a) {
return r << a | r >>> 32 - a;
}

function str2binb(r) {
for (var a = Array(), n = (1 << sha1_chrsz) - 1, h = 0; h < r.length * sha1_chrsz; h += sha1_chrsz) a[h >> 5] |= (r.charCodeAt(h / sha1_chrsz) & n) << 24 - h % 32;
return a;
}

function binb2str(r) {
for (var a = "", n = (1 << sha1_chrsz) - 1, h = 0; h < 32 * r.length; h += sha1_chrsz) a += String.fromCharCode(r[h >> 5] >>> 24 - h % 32 & n);
return a;
}

function binb2hex(r) {
for (var a = sha1_hexcase ? "0123456789ABCDEF" : "0123456789abcdef", n = "", h = 0; h < 4 * r.length; h++) n += a.charAt(r[h >> 2] >> 8 * (3 - h % 4) + 4 & 15) + a.charAt(r[h >> 2] >> 8 * (3 - h % 4) & 15);
return n;
}

function binb2b64(r) {
for (var a = "", n = 0; n < 4 * r.length; n += 3) for (var h = (r[n >> 2] >> 8 * (3 - n % 4) & 255) << 16 | (r[n + 1 >> 2] >> 8 * (3 - (n + 1) % 4) & 255) << 8 | r[n + 2 >> 2] >> 8 * (3 - (n + 2) % 4) & 255, s = 0; s < 4; s++) 8 * n + 6 * s > 32 * r.length ? a += sha1_b64pad : a += "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".charAt(h >> 6 * (3 - s) & 63);
return a;
}
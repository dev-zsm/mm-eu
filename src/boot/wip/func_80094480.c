// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct FmtCtx {
    f64 value;
    u8 *out;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} FmtCtx;

extern f64 D_80099830[];
extern f64 D_80099888;
extern char D_80099878[];
extern char D_8009987C[];

s32 func_80094910(s16 *exp, FmtCtx *p);
void func_80094F90(u32 *out, u32 n, u32 base);
s32 func_8008F3A8(u8 *out, char *s, s32 n);
s32 func_800949C8(FmtCtx *p, u8 c, u8 *s, s32 cnt, s32 exp);

s32 func_80094480(FmtCtx *p, u32 fmt) {
    s16 exp;
    s32 c;
    u32 div[2];
    u8 buf[0x20];
    u8 *s2;
    s32 cls;
    s32 s5;
    s32 s1;
    s32 s0;
    s32 a1;
    s32 a3;
    s32 v1;
    s32 n;
    s32 t;
    f64 v;
    f64 f0;

    v = p->value;
    s2 = buf;
    if (p->unk24 < 0) {
        p->unk24 = 6;
    } else if (p->unk24 == 0) {
        c = (u8)fmt;
        if (c == 'g' || c == 'G') {
            p->unk24 = 1;
        }
    }

    cls = func_80094910(&exp, p);
    if (cls > 0) {
        p->unk14 = 3;
        return func_8008F3A8(p->out, (cls == 2) ? D_80099878 : D_8009987C, 3);
    }
    a3 = 0;
    if (cls == 0) {
        exp = 0;
        return func_800949C8(p, (u8)fmt, s2, a3, exp);
    }

    if (v < 0.0) {
        v = -v;
    }
    t = exp * 30103;
    exp = (s16)(t / 100000 - 4);
    a1 = 6;
    v1 = 0;
    if (exp < 0) {
        n = (3 - exp) & ~3;
        exp = (s16)-n;
        if (n > 0) {
            do {
                if (n & 1) {
                    v = v * D_80099830[v1];
                }
                n = n >> 1;
                v1++;
            } while (n > 0);
        }
    } else if (exp > 0) {
        n = exp & 0xFFFC;
        f0 = 1.0;
        exp = (s16)n;
        if (n > 0) {
            do {
                if (n & 1) {
                    f0 = f0 * D_80099830[v1];
                }
                n = n >> 1;
                v1++;
            } while (n > 0);
        }
        v = v / f0;
    }

    c = (u8)fmt;
    if (c == 'f') {
        a1 = (s16)exp + 10;
    }
    s5 = a1 + p->unk24;
    if (s5 >= 0x14) {
        s5 = 0x13;
    }
    if (s5 > 0) {
        buf[0] = '0';
        if (0.0 < v) {
            do {
                s5 -= 8;
                s2 += 8;
                s1 = (s32)v;
                if (s5 > 0) {
                    v = (v - (f64)s1) * D_80099888;
                }
                s0 = 8;
                if (s1 > 0) {
                    s0 = 7;
                    for (;;) {
                        func_80094F90(div, s1, 10);
                        s2--;
                        *s2 = (u8)(div[1] + '0');
                        s1 = div[0];
                        if (s1 <= 0) {
                            s0--;
                            break;
                        }
                        s0--;
                        if (s0 < 0) {
                            break;
                        }
                    }
                    if (s1 > 0) {
                        s0--;
                    }
                } else {
                    s0--;
                }
                if (s0 >= 0) {
                    do {
                        s0--;
                        s2--;
                        *s2 = '0';
                    } while (s0 >= 0);
                } else {
                    s0--;
                }
                s2 += 8;
            } while (s5 > 0 && 0.0 < v);
        }
    }

    s5 = (s32)(s2 - buf) - 1;
    exp = (s16)(exp + 7);
    s2 = buf + 1;
    if (buf[1] == '0') {
        do {
            s2++;
            s5--;
            exp--;
        } while (*s2 == '0');
    }

    c = (u8)fmt;
    if (c == 'f') {
        a1 = (s16)exp + 1;
    } else {
        a1 = (c == 'e' || c == 'E') ? 1 : 0;
    }
    a3 = (s16)(a1 + p->unk24);
    if (s5 < a3) {
        a3 = (s16)s5;
    }
    if (a3 > 0) {
        if (a3 < s5) {
            a1 = (s2[a3] < '5') ? '0' : '9';
        } else {
            a1 = '0';
        }
        v1 = a3 - 1;
        if (a1 == s2[a3 - 1]) {
            do {
                v1--;
                a3--;
            } while (s2[v1 + 1 - 1] == a1);
        }
        if (a1 == '9') {
            s2[v1] = s2[v1] + 1;
        }
        if (v1 < 0) {
            a3 = (s16)(a3 + 1);
            exp = (s16)(exp + 1);
            s2--;
        }
    }

    return func_800949C8(p, (u8)fmt, s2, a3, exp);
}

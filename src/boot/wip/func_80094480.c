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

s32 _Ldunscale(s16 *exp, FmtCtx *p);
void ldiv(u32 *out, u32 n, u32 base);
s32 memcpy(u8 *out, char *s, s32 n);
s32 _Genld(FmtCtx *p, u8 c, u8 *s, s32 cnt, s32 exp);

s32 _Ldtob(FmtCtx *p, u8 type) {
    u8 buff[0x20];
    u8 *ptr;
    f64 val;
    s32 err;
    s16 exp;
    s16 nsig;
    s32 i;
    s32 n;
    s32 j;
    s32 gen;
    s32 lo;
    u32 qr[2];

    ptr = buff;
    val = p->value;
    if (p->unk24 < 0) {
        p->unk24 = 6;
    } else if (p->unk24 == 0 && (type == 'g' || type == 'G')) {
        p->unk24 = 1;
    }
    err = _Ldunscale(&exp, p);
    if (err > 0) {
        return memcpy(p->out, (err == 2) ? D_80099878 : D_8009987C, p->unk14 = 3);
    }
    if (err == 0) {
        nsig = 0;
        exp = 0;
    } else {
        if (val < 0.0) {
            val = -val;
        }
        exp = exp * 30103 / 100000 - 4;
        if (exp < 0) {
            n = (3 - exp) & ~3;
            exp = -n;
            for (i = 0; n > 0; n >>= 1, i++) {
                if ((n & 1) != 0) {
                    val *= D_80099830[i];
                }
            }
        } else if (exp > 0) {
            f64 factor = 1.0;
            exp &= ~3;
            for (n = exp, i = 0; n > 0; n >>= 1, i++) {
                if ((n & 1) != 0) {
                    factor *= D_80099830[i];
                }
            }
            val /= factor;
        }
        gen = ((type == 'f') ? exp + 10 : 6) + p->unk24;
        if (gen > 0x13) {
            gen = 0x13;
        }
        *ptr++ = '0';
        while (gen > 0 && 0.0 < val) {
            lo = val;
            if ((gen -= 8) > 0) {
                val = (val - lo) * D_80099888;
            }
            for (ptr += 8, j = 8; lo > 0 && --j >= 0;) {
                ldiv(qr, lo, 10);
                *--ptr = qr[1] + '0';
                lo = qr[0];
            }
            while (--j >= 0) {
                *--ptr = '0';
            }
            ptr += 8;
        }
        gen = ptr - &buff[1];
        exp += 7;
        for (ptr = &buff[1]; *ptr == '0'; ptr++) {
            gen--;
            exp--;
        }
        nsig = ((type == 'f') ? exp + 1 : ((type == 'e' || type == 'E') ? 1 : 0)) + p->unk24;
        if (gen < nsig) {
            nsig = gen;
        }
        if (nsig > 0) {
            u8 drop = (nsig < gen && ptr[nsig] > '4') ? '9' : '0';
            for (i = nsig; ptr[--i] == drop; --nsig) {
            }
            if (drop == '9') {
                ++ptr[i];
            }
            if (i < 0) {
                --ptr;
                ++nsig;
                ++exp;
            }
        }
    }
    return _Genld(p, type, ptr, nsig, exp);
}

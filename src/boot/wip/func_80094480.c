// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
// COMPILER: ido53
// best attempt: only 'code' differs (ROM leaves it in memory; ours keeps it in s0, 4 extra instr)
#include "types.h"

typedef struct {
    f64 ld;
    char *s;
    s32 unkC;
    s32 unk10;
    s32 n1;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 prec;
} Pft;

typedef struct {
    s32 quot;
    s32 rem;
} Ldiv;

extern f64 D_80099830[];
extern f64 D_80099888;
extern char D_80099878[];
extern char D_8009987C[];

s16 _Ldunscale();
Ldiv ldiv();
void *memcpy();
void _Genld();

void _Ldtob(Pft *args, char code) {
    char buff[0x20];
    char *p = buff;
    f64 ldval = args->ld;
    s16 err;
    s16 nsig;
    s16 xexp;
    s32 i;
    s32 n;
    f64 factor;
    s32 gen;
    s32 j;
    s32 lo;
    Ldiv qr;
    char drop;
    s32 n2;

    if (args->prec < 0) {
        args->prec = 6;
    } else if (args->prec == 0 && (code == 'g' || code == 'G')) {
        args->prec = 1;
    }
    err = _Ldunscale(&xexp, args);
    if (err > 0) {
        memcpy(args->s, (err == 2) ? D_80099878 : D_8009987C, args->n1 = 3);
        return;
    }
    if (err == 0) {
        nsig = 0;
        xexp = 0;
    } else {
        if (ldval < 0.0) {
            ldval = -ldval;
        }
        xexp = xexp * 30103 / 100000 - 4;
        if (xexp < 0) {
            n = (3 - xexp) & ~3;
            xexp = -n;
            for (i = 0; n > 0; n >>= 1, i++) {
                if ((n & 1) != 0) {
                    ldval *= D_80099830[i];
                }
            }
        } else if (xexp > 0) {
            factor = 1.0;
            xexp &= ~3;
            n = xexp;
            for (i = 0; n > 0; n >>= 1, i++) {
                if ((n & 1) != 0) {
                    factor *= D_80099830[i];
                }
            }
            ldval /= factor;
        }
        gen = ((code == 'f') ? xexp + 10 : 6) + args->prec;
        if (gen > 0x13) {
            gen = 0x13;
        }
        *p++ = '0';
        while (gen > 0 && 0.0 < ldval) {
            lo = ldval;
            gen -= 8;
            if (gen > 0) {
                ldval = (ldval - lo) * D_80099888;
            }
            for (p += 8, j = 8; lo > 0 && 0 <= --j;) {
                qr = ldiv(lo, 10);
                *--p = qr.rem + '0';
                lo = qr.quot;
            }
            while (0 <= --j) {
                *--p = '0';
            }
            p += 8;
        }
        gen = p - &buff[1];
        p = &buff[1];
        xexp += 7;
        while (*p == '0') {
            p++;
            gen--;
            xexp--;
        }
        nsig = ((code == 'f') ? xexp + 1 : ((code == 'e' || code == 'E') ? 1 : 0)) + args->prec;
        if (gen < nsig) {
            nsig = gen;
        }
        if (nsig > 0) {
            drop = (nsig < gen && p[nsig] >= '5') ? '9' : '0';
            for (n2 = nsig; p[--n2] == drop; nsig--) {
            }
            if (drop == '9') {
                p[n2]++;
            }
            if (n2 < 0) {
                --p;
                ++nsig;
                ++xexp;
            }
        }
    }
    _Genld(args, code, p, nsig, xexp);
}

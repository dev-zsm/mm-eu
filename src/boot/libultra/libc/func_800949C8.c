// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "printf.h"

void _Genld(Pft *px, char code, char *p, s16 nsig, s16 xexp) {
    if (nsig <= 0) {
        p = D_80099880;
        nsig = 1;
    }
    if (code == 'f' || ((code == 'g' || code == 'G') && xexp >= -4 && xexp < px->prec)) {
        xexp++;
        if (code != 'f') {
            if (!(px->flags & FLAGS_HASH) && nsig < px->prec) {
                px->prec = nsig;
            }
            if ((px->prec -= xexp) < 0) {
                px->prec = 0;
            }
        }
        if (xexp <= 0) {
            px->s[px->n1++] = '0';
            if (px->prec > 0 || (px->flags & FLAGS_HASH)) {
                px->s[px->n1++] = '.';
            }
            if (px->prec < -xexp) {
                xexp = -px->prec;
            }
            px->nz1 = -xexp;
            px->prec += xexp;
            if (px->prec < nsig) {
                nsig = px->prec;
            }
            px->n2 = nsig;
            memcpy(px->s + px->n1, p, nsig);
            px->nz2 = px->prec - nsig;
        } else if (nsig < xexp) {
            memcpy(px->s + px->n1, p, nsig);
            px->n1 += nsig;
            px->nz1 = xexp - nsig;
            if (px->prec > 0 || (px->flags & FLAGS_HASH)) {
                px->s[px->n1] = '.';
                px->n2++;
            }
            px->nz2 = px->prec;
        } else {
            memcpy(px->s + px->n1, p, xexp);
            px->n1 += xexp;
            nsig -= xexp;
            if (px->prec > 0 || (px->flags & FLAGS_HASH)) {
                px->s[px->n1++] = '.';
            }
            if (px->prec < nsig) {
                nsig = px->prec;
            }
            memcpy(px->s + px->n1, p + xexp, nsig);
            px->n1 += nsig;
            px->nz1 = px->prec - nsig;
        }
    } else {
        if (code == 'g' || code == 'G') {
            if (nsig < px->prec) {
                px->prec = nsig;
            }
            if ((px->prec -= 1) < 0) {
                px->prec = 0;
            }
            if (code == 'g') {
                code = 'e';
            } else {
                code = 'E';
            }
        }
        px->s[px->n1++] = *p++;
        if (px->prec > 0 || (px->flags & FLAGS_HASH)) {
            px->s[px->n1++] = '.';
        }
        if (px->prec > 0) {
            nsig--;
            if (px->prec < nsig) {
                nsig = px->prec;
            }
            memcpy(px->s + px->n1, p, nsig);
            px->n1 += nsig;
            px->nz1 = px->prec - nsig;
        }
        p = px->s + px->n1;
        *p++ = code;
        if (xexp >= 0) {
            *p++ = '+';
        } else {
            *p++ = '-';
            xexp = -xexp;
        }
        if (xexp >= 100) {
            if (xexp >= 1000) {
                *p++ = xexp / 1000 + '0', xexp %= 1000;
            }
            *p++ = xexp / 100 + '0', xexp %= 100;
        }
        *p++ = xexp / 10 + '0', xexp %= 10;
        *p++ = xexp + '0';
        px->n2 = (p - px->s) - px->n1;
    }
    if ((px->flags & (FLAGS_MINUS | FLAGS_ZERO)) == FLAGS_ZERO) {
        s32 n = px->n0 + px->n1 + px->nz1 + px->n2 + px->nz2;

        if (n < px->width) {
            px->nz0 = px->width - n;
        }
    }
}

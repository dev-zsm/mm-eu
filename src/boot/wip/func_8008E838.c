// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// best attempt: same instructions and size as the ROM; 278 words differ by register numbers only (ROM: pap in s0, px in s1, va_arg temporaries t8/t9/t0/t1 never reused)
#include "types.h"

typedef struct {
    s64 ll;
    char *s;
    s32 n0;
    s32 nz0;
    s32 n1;
    s32 nz1;
    s32 n2;
    s32 nz2;
    s32 prec;
    s32 width;
    u32 nchar;
    u32 flags;
    u8 qual;
} Pft;

typedef char *va_list;

extern void _Litob(Pft *px, char code);
extern void _Ldtob(Pft *px, char code);
extern s32 strlen(char *s);

#define VA32(ap) (*(s32 *)((*(ap) = (char *)((((s32)*(ap)) + 3 & ~3) + 4)) - 4))
#define VA64(ap) (*(s64 *)((*(ap) = (char *)((((s32)*(ap)) + 7 & ~7) + 8)) - 8))

void _Putfld(Pft *px, va_list *pap, char code, char *ac) {
    char *p;
    s32 v;
    px->n0 = px->nz0 = px->n1 = px->nz1 = px->n2 = px->nz2 = 0;

    switch (code) {
    case 'c':
        ac[px->n0++] = VA32(pap);
        break;
    case 'd':
    case 'i':
        if (px->qual == 'l') {
            px->ll = VA32(pap);
        } else if (px->qual == 'L') {
            px->ll = VA64(pap);
        } else {
            px->ll = VA32(pap);
        }
        if (px->qual == 'h') {
            px->ll = (s16)px->ll;
        }
        if (px->ll < 0) {
            ac[px->n0++] = '-';
        } else if (px->flags & 2) {
            ac[px->n0++] = '+';
        } else if (px->flags & 1) {
            ac[px->n0++] = ' ';
        }
        px->s = &ac[px->n0];
        _Litob(px, code);
        break;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
        if (px->qual == 'l') {
            px->ll = VA32(pap);
        } else if (px->qual == 'L') {
            px->ll = VA64(pap);
        } else {
            px->ll = VA32(pap);
        }
        if (px->qual == 'h') {
            px->ll = (u16)px->ll;
        } else if (px->qual == 0) {
            px->ll = (u32)px->ll;
        }
        if (px->flags & 8) {
            ac[px->n0++] = '0';
            if (code == 'x' || code == 'X') {
                ac[px->n0++] = code;
            }
        }
        px->s = &ac[px->n0];
        _Litob(px, code);
        break;
    case 'e':
    case 'f':
    case 'g':
    case 'E':
    case 'G':
        if (px->qual == 'L') {
            p = *pap;
            v = (s32)p;
            p = ((v & 1) ? (*pap = (char *)(v + 7)) - 22 : ((v & 2) ? (*pap = (char *)(v + 10)) - 40 : (*pap = (char *)(((v + 7) & ~7) + 8))));
            *(f64 *)px = *(f64 *)(p - 8);
        } else {
            p = *pap;
            v = (s32)p;
            p = ((v & 1) ? (*pap = (char *)(v + 7)) - 22 : ((v & 2) ? (*pap = (char *)(v + 10)) - 40 : (*pap = (char *)(((v + 7) & ~7) + 8))));
            *(f64 *)px = *(f64 *)(p - 8);
        }
        if (*(u16 *)px & 0x8000) {
            ac[px->n0++] = '-';
        } else if (px->flags & 2) {
            ac[px->n0++] = '+';
        } else if (px->flags & 1) {
            ac[px->n0++] = ' ';
        }
        px->s = &ac[px->n0];
        _Ldtob(px, code);
        break;
    case 'n':
        if (px->qual == 'h') {
            *(s16 *)VA32(pap) = px->nchar;
        } else if (px->qual == 'l') {
            *(s32 *)VA32(pap) = px->nchar;
        } else if (px->qual == 'L') {
            *(s64 *)VA32(pap) = px->nchar;
        } else {
            *(s32 *)VA32(pap) = px->nchar;
        }
        break;
    case 'p':
        px->ll = VA32(pap);
        px->s = &ac[px->n0];
        _Litob(px, 'x');
        break;
    case 's':
        px->s = (char *)VA32(pap);
        px->n1 = strlen(px->s);
        if (px->prec >= 0 && px->prec < px->n1) {
            px->n1 = px->prec;
        }
        break;
    case '%':
        ac[px->n0++] = '%';
        break;
    default:
        ac[px->n0++] = code;
        break;
    }
}

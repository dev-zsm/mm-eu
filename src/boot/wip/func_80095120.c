// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    s64 ll;
    u8 *s;
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

typedef struct {
    s64 quot;
    s64 rem;
} LldivT;

extern u8 D_80098370[];
extern u8 D_80098384[];

u64 __ull_rem(u64 a, u64 b);
u64 __ull_div(u64 a, u64 b);
void memcpy(void *dst, void *src, u32 n);
LldivT lldiv(s64 num, s64 den);

void _Litob(Pft *args, char type) {
    u8 buff[0x18];
    u8 *digs;
    s32 base;
    s32 i;
    u64 ullval;

    if (type == 'X') {
        digs = D_80098384;
    } else {
        digs = D_80098370;
    }
    base = (type == 'o') ? 8 : ((type != 'x' && type != 'X') ? 10 : 16);
    i = sizeof(buff);
    ullval = args->ll;
    if ((type == 'd' || type == 'i') && args->ll < 0) {
        ullval = -ullval;
    }
    if (ullval != 0 || args->prec != 0) {
        buff[--i] = digs[ullval % base];
    }
    args->ll = ullval / base;
    while (args->ll > 0 && i > 0) {
        LldivT qr = lldiv(args->ll, base);

        args->ll = qr.quot;
        buff[--i] = digs[qr.rem];
    }
    args->n1 = sizeof(buff) - i;
    memcpy(args->s, buff + i, args->n1);
    if (args->n1 < args->prec) {
        args->nz0 = args->prec - args->n1;
    }
    if (args->prec < 0 && (args->flags & 0x14) == 0x10) {
        i = args->width - args->n0 - args->nz0 - args->n1;
        if (i > 0) {
            args->nz0 += i;
        }
    }
}

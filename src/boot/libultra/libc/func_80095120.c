// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "libultra_libc.h"
#include "printf.h"

void _Litob(Pft *args, char type) {
    char buff[0x18];
    char *digs;
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
        lldiv_t qr = lldiv(args->ll, base);

        args->ll = qr.quot;
        buff[--i] = digs[qr.rem];
    }
    args->n1 = sizeof(buff) - i;
    memcpy(args->s, buff + i, args->n1);
    if (args->n1 < args->prec) {
        args->nz0 = args->prec - args->n1;
    }
    if (args->prec < 0 && (args->flags & (FLAGS_MINUS | FLAGS_ZERO)) == FLAGS_ZERO) {
        i = args->width - args->n0 - args->nz0 - args->n1;
        if (i > 0) {
            args->nz0 += i;
        }
    }
}

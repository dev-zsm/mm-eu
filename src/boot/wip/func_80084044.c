// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u16 *buf;      /* 0x00 */
    u16 w;         /* 0x04 */
    u16 h;         /* 0x06 */
    u16 unk08;     /* 0x08 */
    u16 unk0A;     /* 0x0A */
    u16 unk0C;     /* 0x0C */
    u16 unk0E;     /* 0x0E */
    u16 pixOn;     /* 0x10 */
    u16 pixOff;    /* 0x12 */
    u16 x;         /* 0x14 */
    u16 y;         /* 0x16 */
    u32 *tbl;      /* 0x18 */
    u8 cnt;        /* 0x1C */
    u8 rows;       /* 0x1D */
} Ctx;

extern Ctx *D_80096D80;

void func_80084044(u8 m) {
    Ctx *p;
    u16 *base;
    u32 *t;
    u32 mask0;
    u32 mask;
    s32 row;
    s32 col;
    s32 ta;

    p = D_80096D80;
    ta = (m & 4) >> 2;
    t = p->tbl + ((m >> 3) * 16 + ta);
    base = p->buf + p->w * p->y + p->x;

    if (p->x < p->unk0C) return;
    if (p->x + p->cnt - 1 > p->unk0E) return;
    if (p->y < p->unk08) return;
    if (p->y + p->rows - 1 > p->unk0A) return;
    if (p->rows <= 0) return;

    mask0 = 0x10000000u << (m & 3);
    row = 0;
    do {
        mask = mask0;
        col = 0;
        if (p->cnt > 0) {
            do {
                if (*t & mask) {
                    base[col] = p->pixOn;
                } else if (p->pixOff & 1) {
                    base[col] = p->pixOff;
                }
                mask >>= 4;
                col++;
            } while (col < p->cnt);
        }
        base += p->w;
        t += 2;
        row++;
    } while (row < p->rows);
}

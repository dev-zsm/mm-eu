// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s64 value;      /* 0x00 */
    void *out;      /* 0x08 */
    s32 unk0C;      /* 0x0C */
    s32 pad10;      /* 0x10 */
    s32 len14;      /* 0x14 */
    s32 unk18;      /* 0x18 */
    s32 unk1C;      /* 0x1C */
    s32 unk20;      /* 0x20 */
    s32 width;      /* 0x24 */
    s32 unk28;      /* 0x28 */
    s32 unk2C;      /* 0x2C */
    s32 flags;      /* 0x30 */
} FmtCtx;

typedef struct {
    s64 quot;
    s64 rem;
} DivResult64;

extern u8 D_80098370[];
extern u8 D_80098384[];

s64 func_80088A0C(s64 num, s64 den);
s64 func_80088A48(s64 num, s64 den);
void func_8008F3A8(void *out, u8 *buf, s32 len);
DivResult64 func_80095014(s64 num, s64 den);

void func_80095120(FmtCtx *s, s32 a1) {
    DivResult64 dr;
    s64 bs;
    s64 dd;
    s64 v;
    u8 buf[0x18];
    u8 *digits;
    s32 c;
    s32 base;
    s32 pos;
    s32 len;

    c = a1 & 0xFF;
    digits = (c == 'X') ? D_80098384 : D_80098370;
    base = (c == 'o') ? 8 : ((c == 'x' || c == 'X') ? 16 : 10);
    pos = 0x18;
    dd = s->value;
    v = dd;
    if ((c == 'd' || c == 'i') && dd < 0) {
        v = -v;
    }
    bs = base;
    if (v != 0 || s->width != 0) {
        pos = 0x17;
        buf[pos] = digits[(u32)func_80088A0C(v, bs)];
    }
    v = func_80088A48(v, bs);
    s->value = v;
    if (v > 0 && pos > 0) {
        do {
            dr = func_80095014(v, bs);
            s->value = dr.quot;
            pos--;
            buf[pos] = digits[(u32)dr.rem];
            v = s->value;
        } while (v > 0 && pos > 0);
    }
    len = 0x18 - pos;
    s->len14 = len;
    func_8008F3A8(s->out, buf + pos, len);
    if (len < s->width) {
        s->pad10 = s->width - len;
    }
    if (s->width < 0 && (s->flags & 0x14) == 0x10) {
        s32 extra = s->unk28 - s->unk0C - s->pad10 - len;
        if (extra > 0) {
            s->pad10 += extra;
        }
    }
}

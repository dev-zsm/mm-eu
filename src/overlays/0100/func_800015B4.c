#include "types.h"

typedef struct {
    u8 pad0[0x24E];
    s8 unk24E;
    u8 pad24F[0xD9];
    s32 unk328;
} Ovl0100Obj;

s32 func_800015B4(s32 a, s32 b, s32 *c, s32 d, s32 e, Ovl0100Obj *f) {
    if (f->unk24E == -1) {
        f->unk328 = *c;
        *c = 0;
    }
    return 0;
}

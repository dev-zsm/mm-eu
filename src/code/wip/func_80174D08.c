#include "types.h"

typedef struct {
    u8 pad0[0xA2];
    u8 unkA2;
} Obj;

extern s64 D_80096D10;
extern s64 D_801F3370;

s32 func_80174D08(Obj *o) {
    s64 a = (s64)(o->unkA2 & 0xFF) * D_80096D10 * 64 / 3;
    s64 b = D_801F3370 * 64 / 3;

    return (s32)a - (s32)b;
}

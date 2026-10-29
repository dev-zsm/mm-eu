#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 b;
    u8 pad1[0x34C - 0x14C];
    s32 c;
    u8 pad2[0x388 - 0x350];
    s32 d;
} T;

s32 func_80009F24(T *a) {
    return a->d != 0 && a->c == 0 && a->b != 3;
}

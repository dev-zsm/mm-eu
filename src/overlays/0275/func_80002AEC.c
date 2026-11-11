// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0275.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V0275;

void func_80182B28();
extern V0275 D_809AE1DC;

void func_80002AEC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    s32 pad;
    V0275 v = D_809AE1DC;

    if (arg1 == 0xF) {
        func_80182B28(&v, arg4 + 0x3C);
    }
}

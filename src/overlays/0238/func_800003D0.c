// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V0238;

void func_80182B28();
extern V0238 D_80974F68;

void func_800003D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    s32 pad;
    V0238 v = D_80974F68;

    if (arg1 == 9) {
        func_80182B28(&v, arg4 + 0x3C);
    }
}

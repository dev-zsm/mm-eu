// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V0249;

void func_80182B28();
extern V0249 D_80985B30;

void func_80000DB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    s32 pad;
    V0249 v = D_80985B30;

    if (arg1 == 6) {
        func_80182B28(&v, arg4 + 0x3C);
    }
}

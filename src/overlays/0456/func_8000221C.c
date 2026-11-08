// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0456.h"

typedef struct V {
    s32 x;
    s32 y;
    s32 z;
} V;

extern V D_80AF67FC;
void func_80182B28();

void func_8000221C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 pad;
    V sp18;

    sp18 = D_80AF67FC;
    if (arg1 == 7) {
        func_80182B28(&sp18, arg4 + 0x3C);
    }
}

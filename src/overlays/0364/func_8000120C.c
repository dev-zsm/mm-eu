// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct V {
    s32 x;
    s32 y;
    s32 z;
} V;

extern V D_80A5BECC;
void func_8018132C(f32, f32, f32, s32);
void func_80182B28();

void func_8000120C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    V sp1C;

    sp1C = D_80A5BECC;
    if (arg1 == 2) {
        func_8018132C(0.0f, 0.0f, 0.0f, 1);
        func_80182B28(&sp1C, arg4 + 0x1CC);
    }
}

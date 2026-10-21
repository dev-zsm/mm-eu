// FLAGS: -O1 -g3 -mips2 -trapuv
#include "types.h"

void func_800847DC(s32 a0, s32 *a1);

void func_8008482C(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 pad[2];

    func_800847DC(a0, &a1);
}

// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 pad0;
    s32 unk4;
} Struct800982B4;

extern Struct800982B4 *D_800982B4;

s32 func_80091C00(void);
void func_80091C70(s32 a);

s32 func_8008ABB0(void) {
    s32 temp_a0;
    s32 sp18;

    temp_a0 = func_80091C00();
    sp18 = D_800982B4->unk4;
    func_80091C70(temp_a0);
    return sp18;
}

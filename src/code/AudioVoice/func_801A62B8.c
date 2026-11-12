// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xC];
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
} Struct_801F4DE0;

extern Struct_801F4DE0 D_801F4DE0;

void func_801A62B8(u16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4) {
    D_801F4DE0.unkC = arg0;
    D_801F4DE0.unkE = arg1;
    D_801F4DE0.unk10 = arg2;
    D_801F4DE0.unk12 = arg3;
    D_801F4DE0.unk14 = arg4;
}

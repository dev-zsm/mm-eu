// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x24];
    u8 unk24[0x3C4];
    u8 unk3E8;
} Act;
unsigned long long func_800A8248();
void func_800B6490();
void func_80000800(Act *arg0, s32 arg1) {
    if (arg0->unk3E8 & 8) {
        Act *new_var;
        if (0) { }
        new_var = arg0;
        func_800A8248(arg1, new_var, new_var->unk24, 0x10);
        func_800B6490(new_var);
    }
}

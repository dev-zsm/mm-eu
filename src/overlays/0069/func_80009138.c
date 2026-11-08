// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_801378E0();
extern u8 *D_80888628[];

void func_80009138(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x144) = 0x17;
    M2C_FIELD(arg0, s32 *, 0x20C) = 4;
    func_801378E0(arg0 + 0x1A4, *(s32 *)(D_80888628[M2C_FIELD(arg0, s32 *, 0x150)] + 0x10), arg0);
    M2C_FIELD(arg0, s32 *, 0x1E8) |= 0x10000;
}

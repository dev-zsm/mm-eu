// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0069.h"

void func_801377D0();
extern u8 *D_80888628[];

void func_800034F0(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x148) = 0;
    M2C_FIELD(arg0, s32 *, 0x14C) = 0;
    M2C_FIELD(arg0, s32 *, 0x144) = 0xC;
    M2C_FIELD(arg0, s32 *, 0x20C) = 6;
    M2C_FIELD(arg0, s32 *, 0x230) = 0;
    func_801377D0(arg0 + 0x1A4, *(s32 *)(D_80888628[M2C_FIELD(arg0, s32 *, 0x150)] + 0x18), arg0);
}

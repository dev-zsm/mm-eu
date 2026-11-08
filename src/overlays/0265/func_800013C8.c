// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0265.h"

void func_80992908();
void func_800B8C4C();
extern u8 D_80993A40;

void func_800013C8(u8 *arg0) {
    func_80992908(arg0, 3);
    M2C_FIELD(arg0, s16 *, 0x27C) = 3;
    M2C_FIELD(arg0, s16 *, 0x32) = M2C_FIELD(arg0, s16 *, 0x92);
    func_800B8C4C(arg0, 0x1806);
    M2C_FIELD(arg0, u8 *, 0x36D) |= 4;
    M2C_FIELD(arg0, u8 **, 0x278) = &D_80993A40;
}

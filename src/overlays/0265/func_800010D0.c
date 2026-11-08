// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0265.h"

void func_80992908();
extern u8 D_80993748;

void func_800010D0(u8 *arg0, u8 *arg1) {
    u8 *player = M2C_FIELD(arg1, u8 **, 0x1CCC);

    func_80992908(arg0, 2);
    M2C_FIELD(arg0, s16 *, 0x280) = 0x258;
    M2C_FIELD(arg0, s16 *, 0x27C) = 2;
    M2C_FIELD(arg0, s16 *, 0x27E) = M2C_FIELD(player, s16 *, 0xBE);
    M2C_FIELD(arg0, u8 **, 0x278) = &D_80993748;
}

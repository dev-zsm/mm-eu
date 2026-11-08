// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_809FBD90();
extern u8 D_809FC5D0;

void func_80000B08(u8 *arg0, u8 *arg1) {
    u8 *player = M2C_FIELD(arg1, u8 **, 0x1CCC);

    func_809FBD90(arg0, 3);
    M2C_FIELD(player, s16 *, 0x118) = 0xA;
    M2C_FIELD(arg0, s16 *, 0x3C2) = 3;
    M2C_FIELD(arg0, s16 *, 0x3C6) = 3;
    M2C_FIELD(arg0, u8 **, 0x230) = &D_809FC5D0;
}

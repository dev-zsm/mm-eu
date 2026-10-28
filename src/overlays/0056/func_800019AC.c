// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D6BC(u8 *);                      /* extern */

void func_800019AC(s32 arg0, u8 *arg1, s32 arg2) {
    M2C_FIELD(arg1, s32 *, 0xAC4) = arg2;
    M2C_FIELD(arg1, s8 *, 0xACE) = 0;
    M2C_FIELD(arg1, f32 *, 0xAC8) = 0.0f;
    func_8082D6BC(arg1);
}

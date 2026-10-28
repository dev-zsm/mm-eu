// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BFA214(u8 *, s32);                 /* extern */
M2C_UNK func_80BFA464(u8 *, s32);                 /* extern */
M2C_UNK func_80BFA4B8(u8 *, s32);                 /* extern */

void func_800004E4(u8 *arg0, s32 arg1) {
    func_80BFA4B8(arg0, arg1);
    func_80BFA214(arg0, arg1);
    func_80BFA464(arg0, arg1);
    M2C_FIELD(arg0, s16 *, 0x1AE) = (s16) (M2C_FIELD(arg0, s16 *, 0x1AE) + 1);
}

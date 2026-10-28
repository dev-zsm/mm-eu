// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_809A7234(u8 *);                          /* extern */
s32 func_809A73B0(u8 *);                          /* extern */
extern M2C_UNK D_809A7554;

void func_80001680(u8 *arg0) {
    if ((func_809A7234(arg0) != 0) || (func_809A73B0(arg0) != 0)) {
        func_800F1944(M2C_FIELD(arg0, s16 *, 0x430));
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809A7554;
    }
}

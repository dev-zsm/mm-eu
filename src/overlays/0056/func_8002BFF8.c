// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(s32, u8 *);                     /* extern */
M2C_UNK func_8082D1EC(s32, u8 *, s32);            /* extern */
s32 func_8082E604(u8 *);                          /* extern */
M2C_UNK func_8082F310(u8 *);                      /* extern */
M2C_UNK func_8083E04C(s32, u8 *);                 /* extern */
M2C_UNK func_8085893C(u8 *);                      /* extern */

void func_8002BFF8(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    func_8085893C(arg1);
    if (M2C_FIELD(arg1, s16 *, 0xAE8) != 0) {
        if (func_80136480(arg0, arg1 + 0x240) != 0) {
            func_8082D1EC(arg0, arg1, func_8082E604(arg1));
            M2C_FIELD(arg1, s16 *, 0xAE8) = 0;
        }
        func_8082F310(arg1);
        return;
    }
    func_8083E04C(arg0, arg1);
}

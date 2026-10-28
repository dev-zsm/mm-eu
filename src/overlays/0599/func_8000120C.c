// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
s32 func_801244EC(s32);                             /* extern */
M2C_UNK func_80BCEA14(u8 *);                      /* extern */
M2C_UNK func_80BCFB58(u8 *);                      /* extern */
extern u8 D_801E7E27;

void func_8000120C(u8 *arg0, s32 arg1) {
    func_80BCEA14(arg0);
    if (func_800B8254(arg0, arg1) != 0) {
        func_80BCFB58(arg0);
        return;
    }
    if ((D_801E7E27 & 0x80) && (func_801244EC(arg1) == 2)) {
        M2C_FIELD(arg0, s16 *, 0x116) = 0x2368;
    }
    func_800B8398(arg0, arg1, 0x43160000);
}

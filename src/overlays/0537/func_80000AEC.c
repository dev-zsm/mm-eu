// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80152978(s32, M2C_UNK);                /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B8460C(u8 *);                      /* extern */
M2C_UNK func_80B84A10(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80B84D20;

void func_80000AEC(u8 *arg0, s32 arg1) {
    func_80B8460C(arg0);
    if (func_801529DC(arg1 + 0x4908) == 7) {
        func_80152978(arg1, 0x41);
        M2C_FIELD(arg0, M2C_UNK **, 0x314) = &D_80B84D20;
        func_80B84A10(arg0, 2);
    }
}

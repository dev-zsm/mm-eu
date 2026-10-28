// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_808B7B70(s32, M2C_UNK *);              /* extern */
s32 func_808B7D4C(s32, u8 *);                     /* extern */
M2C_UNK func_808BAFB4(s32, u8 *, M2C_UNK);        /* extern */
extern M2C_UNK D_808B88FC;

void func_80001014(s32 arg0, u8 *arg1) {
    if ((func_808B7D4C(arg0, arg1) == 0) && (func_800F1E2C() != M2C_FIELD(arg1, s16 *, 0x187AC))) {
        func_808B7B70(arg0, &D_808B88FC);
    }
    func_808BAFB4(arg0, arg1, 1);
    func_800B8C4C(arg0, 0x21B8);
}

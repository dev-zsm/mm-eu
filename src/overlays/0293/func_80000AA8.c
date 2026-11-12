#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0293.h"

M2C_UNK func_80115540(s32, M2C_UNK);                /* extern */
M2C_UNK func_80151E7C(s32, u16);                    /* extern */
M2C_UNK func_809F15DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_809F2634;
extern u16 D_809F55F8[];

void func_80000AA8(s32 arg0, u8 *arg1) {
    func_809F15DC(arg1, &D_809F2634);
    func_80151E7C(arg0, D_809F55F8[M2C_FIELD(arg1, s16 *, 0x3CC)]);
    func_80115540(arg0, 6);
    M2C_FIELD(arg1, s32 *, 0x358) = 0;
    M2C_FIELD(arg1, s32 *, 0x390) = 1;
}

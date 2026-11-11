#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0420.h"

M2C_UNK func_800E0F5C(s32, s32);                    /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_80AB9AE4;
extern M2C_UNK D_80ABA5D0;
extern M2C_UNK D_80ABA5FC;
extern M2C_UNK D_80ABA608;
extern M2C_UNK D_80ABA694;

void func_80001D0C(u8 *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg0 + 0x194;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_80ABA5D0);
    func_800E731C(arg0 + 0xA0, &D_80ABA608, &D_80ABA5FC);
    func_800FF8DC(arg0, &D_80ABA694);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80AB9AE4;
}

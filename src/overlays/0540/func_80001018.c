#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0540.h"

M2C_UNK func_800B701C(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80152978(s32, u16);                    /* extern */
extern u8 D_801E6F10;
extern u16 D_80B89EC0[];

s32 func_80001018(s32 arg0, s32 arg1) {
    s32 var_v1;

    func_800B701C(arg1, 0, 0x44);
    if (D_801E6F10 == 4) {
        var_v1 = 0;
    } else {
        var_v1 = D_801E6F10;
    }
    func_80152978(arg1, D_80B89EC0[var_v1]);
    return 0;
}

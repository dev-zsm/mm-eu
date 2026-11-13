#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0478.h"

s32 func_800EDFA0(s32, u16);                        /* extern */
s32 func_800EE03C(s32, u16);                        /* extern */
M2C_UNK func_80B16A94(u8 *, s32, M2C_UNK, f32); /* extern */
extern M2C_UNK D_80B17658;

void func_800014F8(u8 *arg0, s32 arg1) {
    if ((func_800EE03C(arg1, M2C_FIELD(arg0, u16 *, 0x1F0)) != 0) && (*((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, M2C_FIELD(arg0, u16 *, 0x1F0))] == 2)) {
        M2C_FIELD(arg0, s16 *, 0x1E8) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B17658;
    }
    func_80B16A94(arg0, arg1, 0xD, 0);
}

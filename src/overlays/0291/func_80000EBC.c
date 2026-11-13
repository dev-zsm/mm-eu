#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0291.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800EDFA0(s32, M2C_UNK);                    /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80137788(u8 *, s32, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */
M2C_UNK func_809EFA80(u8 *);                      /* extern */
extern M2C_UNK D_809F0320;
extern s32 D_809F11FC;

void func_80000EBC(u8 *arg0, s32 arg1) {
    u8 *temp_a0;

    func_809EFA80(arg0);
    temp_a0 = arg0 + 0x148;
    func_80137070(temp_a0);
    if ((func_800EE03C(arg1, 0x67) != 0) && (*((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, 0x67)] == 4)) {
        M2C_FIELD(arg0, s16 *, 0xBE) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809F0320;
        func_80137788(temp_a0, D_809F11FC, 0x3F800000, 0x40000000, (f32) func_80134AE8(D_809F11FC), 2, 0.0f);
        func_800B8C4C(arg0, 0x6859);
        M2C_FIELD(arg0, s16 *, 0x2F8) = 0;
    }
}

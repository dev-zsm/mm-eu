#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0291.h"

s32 func_800EDFA0(s32, M2C_UNK);                    /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80137788(u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_809EF714(u8 *, s32);                 /* extern */
M2C_UNK func_809EFD0C(u8 *);                      /* extern */
extern M2C_UNK D_809EFEB4;
extern M2C_UNK D_809F11F0;

void func_800007D8(u8 *arg0, s32 arg1) {
    u8 *temp_a0;

    func_809EF714(arg0, arg1);
    temp_a0 = arg0 + 0x148;
    func_80137070(temp_a0);
    if ((func_800EE03C(arg1, 0x67) != 0) && (*((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, 0x67)] == 7)) {
        func_80137788(temp_a0, M2C_FIELD(&D_809F11F0, s32 *, 0x10), 0x3F800000, 0.0f, (f32) func_80134AE8(M2C_FIELD(&D_809F11F0, s32 *, 0x10)), 0, 0.0f);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809EFEB4;
        return;
    }
    if ((func_800EE03C(arg1, 0x67) != 0) && (*((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, 0x67)] == 6)) {
        func_809EFD0C(arg0);
    }
}

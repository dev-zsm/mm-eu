#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0390.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_801377D0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6009CC0;
extern M2C_UNK D_80A9B5A0;

void func_80001C10(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    u8 *temp_a0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
    temp_a0 = arg0 + 0x148;
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    func_80137070(temp_a0);
    if (func_800B8254(arg0, arg1) != 0) {
        func_801377D0(temp_a0, &D_6009CC0);
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9B5A0;
        M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) & 0xFFFB);
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}

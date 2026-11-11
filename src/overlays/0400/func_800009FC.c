#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FF30C(s32, u8 *, u8 *);         /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60014B8;
extern M2C_UNK D_80AA7F1C;
extern f32 D_80AA9344;

void func_800009FC(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, u8 **, 0x120) = arg0;
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_800FF30C(arg0 + 0x294, temp_v0 + 0x24, arg1);
    M2C_FIELD(arg0, s16 *, 0x192) = 0;
    func_80137788(arg0 + 0x148, &D_60014B8, 0x3F800000, 12.0f, 12.0f, 2, -3.0f);
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
    M2C_FIELD(arg0, f32 *, 0x2A0) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + (func_800FEB84(M2C_FIELD(arg0, s16 *, 0xBE)) * 66.0f));
    M2C_FIELD(arg0, f32 *, 0x2A4) = (f32) ((M2C_FIELD(arg0, f32 *, 0xC) - 49.5f) + D_80AA9344);
    M2C_FIELD(arg0, f32 *, 0x2A8) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + (func_800FEB44(M2C_FIELD(arg0, s16 *, 0xBE)) * 66.0f));
    func_800B8C4C(arg0, 0x38BE);
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80AA7F1C;
}

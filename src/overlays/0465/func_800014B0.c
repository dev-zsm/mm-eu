#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0465.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80AFF498(u8 *, s32);                 /* extern */
extern M2C_UNK D_600119C;
extern M2C_UNK D_80B00670;
extern M2C_UNK D_80B021B4;

void func_800014B0(u8 *arg0, s32 arg1) {
    func_80137788(arg0 + 0x144, &D_600119C, 0x3FC00000, 0, (f32) func_80134AE8(&D_600119C), 2, -3.0f);
    if (M2C_FIELD(arg0, u8 *, 0x18C) == 0) {
        M2C_FIELD(arg0, f32 *, 0x2EC) = 110.0f;
        func_80AFF498(arg0, arg1);
        M2C_FIELD(arg0, s8 *, 0x229) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B021B4;
    } else {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    }
    M2C_FIELD(arg0, s16 *, 0x192) = 0xF;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B8C4C(arg0, 0x3873);
    M2C_FIELD(arg0, u8 *, 0x191) = (u8) (M2C_FIELD(arg0, u8 *, 0x191) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B00670;
}

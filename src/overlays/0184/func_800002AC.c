#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_6010880;
extern M2C_UNK D_6010CD8;

void func_800002AC(u8 *arg0) {
    if (func_8008704C() < 0.5f) {
        func_80137934(arg0 + 0x144, &D_6010CD8, 0xC1200000);
        M2C_FIELD(arg0, f32 *, 0x2B4) = 5.0f;
    } else {
        func_80137934(arg0 + 0x144, &D_6010880, 0xC1200000);
        M2C_FIELD(arg0, f32 *, 0x2B4) = 2.5f;
    }
    M2C_FIELD(arg0, u16 *, 0x2B8) = (u16) (M2C_FIELD(arg0, u16 *, 0x2B8) & 0xFFFB);
    M2C_FIELD(arg0, s16 *, 0x2BC) = (s16) (s32) (func_8017A844(4.0e+01f) + 80.0f);
}

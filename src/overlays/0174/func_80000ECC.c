#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6001168;
extern M2C_UNK D_8093FDE8;
extern M2C_UNK D_80940EF8;

void func_80000ECC(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x3E8) & 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x410) = &D_8093FDE8;
        func_80137788(M2C_FIELD(arg0, s32 *, 0x3D4), &D_6001168, 0x3F800000, 0.0f, 35.0f, 2, 0.0f);
        M2C_FIELD(arg0, M2C_UNK **, 0x414) = &D_80940EF8;
        M2C_FIELD(arg0, s16 *, 0x3EC) = 0x5500;
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + 100.0f);
        M2C_FIELD(arg0, f32 *, 0x3F0) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
    }
}

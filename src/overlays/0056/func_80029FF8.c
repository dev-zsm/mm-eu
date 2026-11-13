#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s32 func_80136480(s32, s32, u8 *);                     /* extern */
M2C_UNK func_8082DE44(u8 *);                      /* extern */
extern M2C_UNK D_800B3F30;

s32 func_80029FF8(s32 arg0, u8 *arg1) {
    f32 temp_f0;

    if (func_80136480(arg0, arg1 + 0x240, arg1) != 0) {
        func_8082DE44(arg1);
        temp_f0 = M2C_FIELD(arg1, f32 *, 0xAD0);
        M2C_FIELD(arg1, M2C_UNK **, 0xC8) = &D_800B3F30;
        M2C_FIELD(arg1, u16 *, 0x90) = (u16) (M2C_FIELD(arg1, u16 *, 0x90) | 0x800);
        M2C_FIELD(arg1, s8 *, 0xAE7) = 4;
        M2C_FIELD(arg1, f32 *, 0xCC) = 30.0f;
        M2C_FIELD(arg1, s16 *, 0xAE8) = (s16) (s32) (temp_f0 * 500.0f);
        M2C_FIELD(arg1, f32 *, 0xB08) = temp_f0;
        M2C_FIELD(arg1, f32 *, 0xB0C) = 0.0f;
        M2C_FIELD(arg1, s16 *, 0x16) = (s16) M2C_FIELD(arg1, s16 *, 0xAD4);
        return 1;
    }
    return 0;
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6002484;
extern M2C_UNK D_6002E7C;
extern M2C_UNK D_8090EA10;

void func_80000578(u8 *arg0) {
    f32 temp_f0;

    temp_f0 = (f32) func_80134AE8(&D_6002484);
    if (M2C_FIELD(arg0, u8 *, 0x2F4) != 0) {
        M2C_FIELD(arg0, s16 *, 0x2F6) = 0xA;
    } else {
        M2C_FIELD(arg0, s16 *, 0x2F6) = 0;
    }
    func_80137788(arg0 + 0x144, &D_6002E7C, 0x3F800000, temp_f0, temp_f0, 2, (f32) M2C_FIELD(arg0, s16 *, 0x2F6));
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090EA10;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}

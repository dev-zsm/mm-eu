#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000114;
extern M2C_UNK D_80AFFE98;

void func_80000D30(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
    if (M2C_FIELD(arg0, u8 *, 0x18C) == 0) {
        M2C_FIELD(arg0, s8 *, 0x320) = 9;
        M2C_FIELD(arg0, u8 *, 0x31D) = (u8) (M2C_FIELD(arg0, u8 *, 0x31D) | 4);
        func_80137934(arg0 + 0x144, &D_6000114, 0xC0A00000, arg0);
    }
    M2C_FIELD(arg0, s16 *, 0x192) = 5;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, u8 *, 0x191) = (u8) (M2C_FIELD(arg0, u8 *, 0x191) | 8);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AFFE98;
}

#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80902150();                            /* extern */
extern M2C_UNK D_80903AD8;

void func_80001900(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    M2C_FIELD(arg0, f32 *, 0x78) = -10.0f;
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    if (M2C_FIELD(arg0, f32 *, 0x68) < -1.0f) {
        M2C_FIELD(arg0, f32 *, 0x68) = -1.0f;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x24);
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) - 20.0f);
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x2C);
    func_80902150();
    M2C_FIELD(arg0, s16 *, 0x240) = 0xF;
    M2C_FIELD(arg0, s8 *, 0x279) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x23C) = &D_80903AD8;
    M2C_FIELD(arg0, s32 *, 0x248) = 5;
    M2C_FIELD(arg0, f32 *, 0x24C) = 0.0f;
}

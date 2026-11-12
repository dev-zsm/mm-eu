#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0228.h"

extern M2C_UNK D_8096A0BC;
extern f32 D_8096A628;

void func_800019EC(u8 *arg0) {
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x98);
    M2C_FIELD(arg0, u8 *, 0x171) = (u8) (M2C_FIELD(arg0, u8 *, 0x171) | 1);
    M2C_FIELD(arg0, u8 *, 0x172) = (u8) (M2C_FIELD(arg0, u8 *, 0x172) | 1);
    if (temp_f0 < 200.0f) {
        var_f2 = 200.0f;
    } else {
        var_f2 = temp_f0;
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 17.5f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) (((var_f2 - 200.0f) * D_8096A628) + 3.0f);
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFE);
    M2C_FIELD(arg0, s16 *, 0x14A) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096A0BC;
}

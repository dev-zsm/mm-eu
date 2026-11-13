#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0590.h"

extern f32 D_80BC87CC;
extern f32 D_80BC87D0;

void func_80000BB8(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f2;
    u8 temp_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    temp_v1 = M2C_FIELD(temp_v0, u8 *, 0x14B);
    switch (temp_v1) {                              /* irregular */
        case 3:
            M2C_FIELD(arg0, f32 *, 0x2B8) = 7.0f;
            break;
        case 1:
            if (M2C_FIELD(temp_v0, s32 *, 0xA74) & 0x1000) {
            M2C_FIELD(arg0, f32 *, 0x2B8) = 19.0f;
            } else {
            M2C_FIELD(arg0, f32 *, 0x2B8) = 7.0f;
            }
            break;
        case 2:
            M2C_FIELD(arg0, f32 *, 0x2B8) = 7.0f;
            break;
        case 4:
            if (M2C_FIELD(temp_v0, s32 *, 0xA6C) & 0x800000) {
            M2C_FIELD(arg0, f32 *, 0x2B8) = 16.0f;
            } else {
            M2C_FIELD(arg0, f32 *, 0x2B8) = 7.0f;
            }
            break;
    }
    M2C_FIELD(arg0, f32 *, 0x1B0) = (f32) (M2C_FIELD(arg0, f32 *, 0x2B8) / 6.0f);
    if (M2C_FIELD(arg0, f32 *, 0x98) > 800.0f) {
        M2C_FIELD(arg0, f32 *, 0x2B8) = (f32) (M2C_FIELD(arg0, f32 *, 0x2B8) * 0.5f);
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) > 500.0f) {
        M2C_FIELD(arg0, f32 *, 0x2B8) = (f32) (M2C_FIELD(arg0, f32 *, 0x2B8) * D_80BC87CC);
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) < 150.0f) {
        M2C_FIELD(arg0, f32 *, 0x2B8) = (f32) (M2C_FIELD(arg0, f32 *, 0x2B8) * D_80BC87D0);
    }
}

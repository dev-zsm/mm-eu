#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0517.h"

f32 func_8008704C();                                /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_80B6AB38(u8 *, M2C_UNK, u8 *);     /* extern */
extern M2C_UNK D_80B6C32C;

void func_80001F48(u8 *arg0, u8 *arg1) {
    u8 *sp24;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_80B6AB38(arg0, 3, arg1);
    if (func_800FEB84((s16) (M2C_FIELD(sp24, s16 *, 0xBE) - M2C_FIELD(arg0, s16 *, 0xBE))) > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x70) = -10.0f;
    } else if (func_800FEB84((s16) (M2C_FIELD(sp24, s16 *, 0xBE) - M2C_FIELD(arg0, s16 *, 0xBE))) < 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    } else if (func_8008704C() > 0.5f) {
        M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    } else {
        M2C_FIELD(arg0, f32 *, 0x70) = -10.0f;
    }
    M2C_FIELD(arg0, f32 *, 0x164) = 1.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x2B2) = 6;
    M2C_FIELD(arg0, s16 *, 0x2B0) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x2AC) = &D_80B6C32C;
    M2C_FIELD(arg0, f32 *, 0x2E0) = 0.0f;
}

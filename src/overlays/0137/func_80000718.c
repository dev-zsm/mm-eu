#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0137.h"

f32 func_800FEB84(s16, u8 *);                     /* extern */

void func_80000718(u8 *arg0) {
    f32 temp_f2;
    f32 sp18;

    sp18 = func_800FEB84(M2C_FIELD(arg0, s16 *, 0x244), arg0);
    M2C_FIELD(arg0, f32 *, 0xC4) = (f32) (((func_800FEB84(M2C_FIELD(arg0, s16 *, 0x246), arg0) * 5.0f) + (sp18 * 10.0f)) + M2C_FIELD(arg0, f32 *, 0xC4));
    temp_f2 = M2C_FIELD(arg0, f32 *, 0xC4);
    if (temp_f2 < -200.0f) {
        M2C_FIELD(arg0, f32 *, 0xC4) = -200.0f;
        return;
    }
    if (temp_f2 > 200.0f) {
        M2C_FIELD(arg0, f32 *, 0xC4) = 200.0f;
    }
}

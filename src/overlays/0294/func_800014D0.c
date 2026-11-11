#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0294.h"

M2C_UNK func_800E26E8(s32, s32, u8 *, u8 *);    /* extern */

void func_800014D0(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x27A) = (s16) (s32) (M2C_FIELD(arg0, f32 *, 0x27C) * (f32) M2C_FIELD(arg0, s16 *, 0x272));
    func_800E26E8(arg1, arg1 + 0x18884, arg0 + 0x22C, arg0);
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_8094D54C(u8 *);                      /* extern */
M2C_UNK func_8094D608(u8 *);                      /* extern */
M2C_UNK func_8094D7A8(u8 *);                      /* extern */
M2C_UNK func_8094E590(u8 *, s32);                 /* extern */
extern M2C_UNK D_8094E388;

void func_800013AC(u8 *arg0, s32 arg1) {
    s16 temp_v1;

    func_80137070(arg0 + 0x144);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x2BC);
    if (temp_v1 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2BC) = (s16) (temp_v1 - 1);
        if (M2C_FIELD(arg0, s16 *, 0x2BC) == 0) {
            if (M2C_FIELD(arg0, u16 *, 0x2B8) & 4) {
                func_8094D54C(arg0);
            } else {
                func_8094D608(arg0);
            }
        }
    }
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2C4) = &D_8094E388;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x2B4) = 0.0f;
        func_8094E590(arg0, arg1);
    } else if ((M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) && (func_800B70A4(arg0, 0x3000, arg1) != 0)) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
    func_8094D7A8(arg0);
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_808D7744(u8 *, f32);                 /* extern */
M2C_UNK func_808D781C(u8 *, M2C_UNK);             /* extern */
extern f32 D_808D7EB0;
extern f32 D_808D7EB4;
extern f32 D_808D7EB8;
extern f32 D_808D7EBC;
extern f32 D_808D7EC0;

void func_800009FC(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x19C) <= 0) {
        if (M2C_FIELD(arg0, s16 *, 0x19E) != 0) {
            M2C_FIELD(arg0, s16 *, 0x19E) = 0;
            func_808D7744(arg0, (func_8008704C() * 0.5f) + D_808D7EB0);
            if (M2C_FIELD(arg0, f32 *, 0x98) < 60.0f) {
                M2C_FIELD(arg0, s16 *, 0x19C) = (s16) ((s32) (func_8008704C() * 5.5f) + 4);
            } else {
                M2C_FIELD(arg0, s16 *, 0x19C) = (s16) ((s32) (func_8008704C() * 40.5f) + 4);
            }
        } else {
            M2C_FIELD(arg0, s16 *, 0x19E) = 1;
            if (M2C_FIELD(arg0, f32 *, 0x98) < 60.0f) {
                M2C_FIELD(arg0, s16 *, 0x19C) = (s16) ((s32) (func_8008704C() * 10.5f) + 4);
                func_808D7744(arg0, (func_8008704C() * D_808D7EB4) + D_808D7EB8);
            } else {
                M2C_FIELD(arg0, s16 *, 0x19C) = (s16) ((s32) (func_8008704C() * 10.5f) + 4);
                func_808D7744(arg0, (func_8008704C() * D_808D7EBC) + D_808D7EC0);
            }
        }
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) < 120.0f) {
        M2C_FIELD(arg0, s16 *, 0x1A0) = (s16) (M2C_FIELD(arg0, s16 *, 0x1A0) + 1);
    } else {
        M2C_FIELD(arg0, s16 *, 0x1A0) = 0;
    }
    if (M2C_FIELD(arg0, s16 *, 0x1A0) >= 0x50) {
        func_808D781C(arg0, 1);
        return;
    }
    func_808D781C(arg0, 0);
}

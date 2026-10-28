// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80953980(u8 *, M2C_UNK *);           /* extern */
s32 func_8095398C(u8 *);                          /* extern */
s16 func_80953B90(u8 *);                          /* extern */
extern M2C_UNK D_80953CD8;
extern M2C_UNK D_80953D10;
extern M2C_UNK D_80953DF0;

void func_80000144(u8 *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;

    if (func_8095398C(arg0) == 0) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x14);
        if ((temp_v0 > 0) && (temp_v0 < 8)) {
            M2C_FIELD(arg0, s8 *, 0x1F) = (s8) (temp_v0 - 1);
        }
        func_800FF8DC(arg0, &D_80953DF0);
        if (M2C_FIELD(arg0, s16 *, 0x16) < 0) {
            func_80953980(arg0, &D_80953D10);
        } else {
            func_80953980(arg0, &D_80953CD8);
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x40001);
            M2C_FIELD(arg0, s16 *, 0x116) = func_80953B90(arg0);
        }
        M2C_FIELD(arg0, s16 *, 0xC0) = 0;
        temp_v0_2 = M2C_FIELD(arg0, s16 *, 0xC0);
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0_2;
        M2C_FIELD(arg0, s16 *, 0xBC) = temp_v0_2;
    }
}

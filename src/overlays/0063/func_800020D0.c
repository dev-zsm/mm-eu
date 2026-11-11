#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80869788(u8 *, s32);                 /* extern */
M2C_UNK func_80869814(u8 *, s32);                 /* extern */
extern M2C_UNK D_6004298;
extern M2C_UNK D_8086B60C;

void func_800020D0(u8 *arg0, s32 arg1) {
    func_801377D0(arg0 + 0x144, &D_6004298);
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2B8) + M2C_FIELD(arg0, s16 *, 0xBE));
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0x2B8) = 0;
    M2C_FIELD(arg0, s16 *, 0x2B6) = 5;
    func_80869788(arg0, arg1);
    func_80869814(arg0, arg1);
    func_800B8C4C(arg0, 0x2902);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086B60C;
}

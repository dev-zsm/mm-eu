// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80AF8638(u8 *);                      /* extern */
M2C_UNK func_80AF865C(u8 *);                      /* extern */
extern M2C_UNK D_6008040;
extern M2C_UNK D_80AF8B70;
extern M2C_UNK D_80AF8CE4;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80AF8CE4);
    func_800CABA0(arg0, 0);
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AF8B70;
        func_80AF8638(arg0);
        return;
    }
    func_800CABC4(arg1, arg0, &D_6008040);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    func_80AF865C(arg0);
}

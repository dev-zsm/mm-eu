// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_809F8130(u8 *);                        /* extern */
M2C_UNK func_809F8F04(u8 *, u8 *);              /* extern */
M2C_UNK func_809F90D8(u8 *);                      /* extern */
extern u8 D_801E7DFD;
extern s32 D_801EAB9C;
extern M2C_UNK D_809F96E0;
extern M2C_UNK D_809F9B44;

void func_800035DC(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;

    if (((((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x70) >> 4) & 0xFF) == 1) && (((M2C_FIELD(arg1, s16 *, 0xA4) == 0x5A) && (D_801EAB9C == 1) && (M2C_FIELD(arg1, u16 *, 0x1F36) == 0)) || !(D_801E7DFD & 8))) {
        temp_v0 = func_809F8130(arg0);
        M2C_FIELD(arg0, u8 **, 0x124) = temp_v0;
        M2C_FIELD(temp_v0, u8 **, 0x124) = arg0;
        func_809F8F04(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F9B44;
        return;
    }
    func_809F90D8(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F96E0;
}

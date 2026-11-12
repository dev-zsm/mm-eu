#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BDF3D4();                            /* extern */
M2C_UNK func_80BDF4B0(u8 *);                      /* extern */
extern u16 D_801E6EFC;
extern M2C_UNK D_80BDFA28;

void func_80000D80(u8 *arg0) {
    if ((s32) D_801E6EFC < 0x4000) {
        func_80BDF3D4();
        M2C_FIELD(arg0, s16 *, 0x414) = (s16) (M2C_FIELD(arg0, s16 *, 0x414) + 5);
        if (M2C_FIELD(arg0, s16 *, 0x414) >= 0xFB) {
            M2C_FIELD(arg0, s16 *, 0x414) = 0xFF;
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
            M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80BDFA28;
        }
        func_80BDF4B0(arg0);
    }
}

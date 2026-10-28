// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115C10(M2C_UNK);                     /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151DF4(u8 *, M2C_UNK, u8 *);     /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_801A00B8();                            /* extern */
M2C_UNK func_801A00E0();                            /* extern */
extern s16 D_801E6F2A;

void func_80000248(u8 *arg0, u8 *arg1) {
    if (func_80147B34(arg1) != 0) {
        if (M2C_FIELD(arg1, u8 *, 0x1692D) == 0) {
            if (D_801E6F2A < 0xA) {
                func_8019FF78(0x4806);
                func_80151DF4(arg1, 0x2B62, arg0);
                M2C_FIELD(arg0, s16 *, 0x14A) = 0x2B62;
                return;
            }
            func_801A00B8();
            func_80115C10(-0xA);
            func_80151DF4(arg1, 0x2B5F, arg0);
            M2C_FIELD(arg0, s16 *, 0x14A) = 0x2B5F;
            return;
        }
        func_801A00E0();
        func_80151DF4(arg1, 0x2B5E, arg0);
        M2C_FIELD(arg0, s16 *, 0x14A) = 0x2B5E;
    }
}

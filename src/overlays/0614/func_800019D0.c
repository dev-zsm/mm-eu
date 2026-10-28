// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80BE3234(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BE4964;
extern s32 D_80BE5790;

void func_800019D0(u8 *arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_80147CC4(arg1);
        func_80BE3234(arg0, 0xF, 0x3F800000);
        D_80BE5790 = 0x64;
        M2C_FIELD(arg0, s16 *, 0x2DC) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE4964;
    }
}

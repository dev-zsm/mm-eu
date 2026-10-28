// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A7C50(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_800B5B64(s32, s16);                    /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern M2C_UNK D_80C0A788;

void func_8000006C(u8 *arg0, s32 arg1) {
    s16 temp_a1;
    s32 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x156) & 2) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C) & 3;
        switch (temp_v0) {                          /* irregular */
        case 0:
            func_8019FF78(0x4803);
            func_800A7C50(arg1, arg0 + 0x24, 0x8000);
            break;
        case 1:
            func_8019FF78(0x4803);
            func_800A7C50(arg1, arg0 + 0x24, 0x8001);
            break;
        case 2:
            func_8019FF78(0x4803);
            func_800A7C50(arg1, arg0 + 0x24, 0x8002);
            break;
        }
        temp_a1 = M2C_FIELD(arg0, s16 *, 0x190);
        if (temp_a1 >= 0) {
            func_800B5B64(arg1, temp_a1);
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x194) = &D_80C0A788;
    }
}

#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0127.h"

M2C_UNK func_800E8C10(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_80115C10(s16);                         /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_801A00B8();                            /* extern */
M2C_UNK func_801A00E0();                            /* extern */
M2C_UNK func_808F37C8(u8 *, u8 *, M2C_UNK);     /* extern */
extern s16 D_801E6F2A;
extern u8 D_801E7E21;

s32 func_800010A0(u8 *arg0, u8 *arg1, M2C_UNK arg2, u8 *arg3) {
    u8 *this = arg1;
    s32 temp_v0;

    if (M2C_FIELD(arg3, u8 *, 0x12025) == 0) {
        func_801A00B8();
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x16978);
        if (D_801E6F2A >= temp_v0) {
            func_80115C10((s16) (temp_v0 * -1));
            if (!(D_801E7E21 & 1)) {
                func_808F37C8(arg1, arg0, 0x3474);
            } else if (M2C_FIELD(arg1, s32 *, 0x4AC) & 8) {
                func_808F37C8(arg1, arg0, 0x3475);
            } else {
                func_800E8C10(arg0, arg1, 0x3475);
            }
        } else {
            func_8019FF78(0x4806);
            func_800E8C10(arg0, arg1, 0x3473);
        }
    } else {
        func_801A00E0();
        func_800E8C10(arg0, arg1, 0x3472);
    }
    return 0;
}

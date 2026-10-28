// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(s32, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
s32 func_801529DC(u8 *);                          /* extern */
extern M2C_UNK D_8093E264;

void func_800003C0(u8 *arg0, u8 *arg1) {
    s32 temp_v0;
    u16 temp_v1;

    func_80137070(arg0 + 0x190);
    temp_v1 = M2C_FIELD(arg1, u16 *, 0x16810);
    if ((temp_v1 == 0xFB9) || (temp_v1 == 0xFBB) || (temp_v1 == 0xFBC)) {
        func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 3, 0x400, 0x80);
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    }
    temp_v0 = func_801529DC(arg1 + 0x4908);
    if (temp_v0 != 2) {
        if ((temp_v0 == 5) && (func_80147B34(arg1) != 0)) {
            func_80147CC4(arg1);
            M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_8093E264;
        }
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_8093E264;
    }
}

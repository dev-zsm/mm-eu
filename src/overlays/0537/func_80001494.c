// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B8460C(u8 *);                      /* extern */
extern M2C_UNK D_80B85878;

void func_80001494(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    func_80B8460C(arg0);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 2, 0x1000, 0x200);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    temp_v0 = func_801529DC(arg1 + 0x4908);
    if (temp_v0 != 2) {
        if ((temp_v0 == 5) && (func_80147B34(arg1) != 0)) {
            func_80147CC4(arg1);
            M2C_FIELD(arg0, M2C_UNK **, 0x314) = &D_80B85878;
            M2C_FIELD(arg0, s16 *, 0x304) = 0;
            func_80B84584(arg0, 6, 2);
        }
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x314) = &D_80B85878;
        M2C_FIELD(arg0, s16 *, 0x304) = 0;
        func_80B84584(arg0, 6, 2);
    }
}

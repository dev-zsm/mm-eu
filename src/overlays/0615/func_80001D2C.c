// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(s32, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_80BE6234(u8 *);                      /* extern */

void func_80001D2C(u8 *arg0, u8 *arg1) {
    u8 *sp2C;

    sp2C = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 1, 0x1388, 0);
    if (M2C_FIELD(arg0, s16 *, 0x2C0) == 0) {
        M2C_FIELD(sp2C, s16 *, 0x118) = 3;
        if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
            func_80147CC4(arg1);
            M2C_FIELD(arg0, s16 *, 0x2C0) = 1;
            M2C_FIELD(sp2C, s32 *, 0xA6C) = (s32) (M2C_FIELD(sp2C, s32 *, 0xA6C) & 0xEFFFFFFF);
        }
    } else if (M2C_FIELD(arg0, f32 *, 0x98) > 200.0f) {
        func_80BE6234(arg0);
    }
}

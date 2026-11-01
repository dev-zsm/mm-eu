// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_801A00B8();                            /* extern */
M2C_UNK func_801A00E0();                            /* extern */
M2C_UNK func_808B7B70(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_808BAFB4(u8 *, u8 *, M2C_UNK);     /* extern */
extern M2C_UNK D_808B8B84;
extern M2C_UNK D_808B8C04;

void func_80000F10(u8 *arg0, u8 *arg1) {
    s32 pad;
    u8 *sp20;

    sp20 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if ((func_801529DC(arg1 + 0x4908) == 4) && (func_80147B34(arg1) != 0)) {
        func_80147CC4(arg1);
        if (M2C_FIELD(arg1, u8 *, 0x1692D) == 0) {
            func_801A00B8();
            func_800B701C(arg1, arg0, 9);
            M2C_FIELD(sp20, f32 *, 0x3A0) = (f32) M2C_FIELD(arg0, f32 *, 0x24);
            M2C_FIELD(sp20, f32 *, 0x3A8) = (f32) M2C_FIELD(arg0, f32 *, 0x2C);
            M2C_FIELD(arg0, s16 *, 0x1CA) = 1;
            func_808B7B70(arg0, &D_808B8C04);
        } else {
            func_801A00E0();
            func_800B701C(arg1, arg0, 6);
            func_808B7B70(arg0, &D_808B8B84);
        }
    }
    func_808BAFB4(arg0, arg1, 1);
    func_800B8C4C(arg0, 0x21B8);
}

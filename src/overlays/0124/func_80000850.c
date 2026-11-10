#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FEE3C(s32, f32, M2C_UNK, u8 *); /* extern */
M2C_UNK func_808E39AC(u8 *);                      /* extern */
extern f32 D_808E4580;

void func_80000850(u8 *arg0, M2C_UNK arg1) {
    func_800FEE3C(arg0 + 0x70, 0, 0x3E4CCCCD, arg0);
    if ((M2C_FIELD(arg0, f32 *, 0x68) <= D_808E4580) || (M2C_FIELD(arg0, u16 *, 0x90) & 2)) {
        if (!(M2C_FIELD(arg0, f32 *, 0x8C) > 0.0f)) {
            func_800B8C4C(arg0, 0x387B);
        }
        M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFD);
        func_808E39AC(arg0);
    }
}

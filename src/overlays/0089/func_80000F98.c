#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(s32, M2C_UNK);                /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BAE44(u8 *, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
s32 func_800C98A8(s32, s32, u8);                    /* extern */
M2C_UNK func_800DFAC4(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FEE3C(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_808AC278(u8 *);                      /* extern */
M2C_UNK func_808AD194(u8 *);                      /* extern */
M2C_UNK func_808AD26C(u8 *);                      /* extern */
M2C_UNK func_808AD440(u8 *);                      /* extern */

void func_80000F98(u8 *arg0, u8 *arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;

    func_800FEE3C(arg0 + 0x70, 0x41A00000, 0x40000000);
    M2C_FIELD(arg0, s16 *, 0x1DC) = (s16) (M2C_FIELD(arg0, s16 *, 0x1DC) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x1DC) == 0) {
        M2C_FIELD(arg0, u8 *, 0x2B5) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B5) & 0xFFFE);
    }
    temp_v0 = func_800C98A8(arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x80), M2C_FIELD(arg0, u8 *, 0x85));
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x90) & 1;
    if ((temp_v1 != 0) || (M2C_FIELD(arg0, f32 *, 0x88) == -32000.0f) || (temp_v0 == 0xC) || (temp_v0 == 0xD)) {
        M2C_FIELD(arg0, u8 *, 0x21C) = (u8) (M2C_FIELD(arg0, u8 *, 0x21C) & 0xFFFE);
        M2C_FIELD(arg0, u8 *, 0x268) = (u8) (M2C_FIELD(arg0, u8 *, 0x268) | 1);
        if (temp_v1 != 0) {
            func_800DFAC4(((s32 *)(arg1 + 0x800))[M2C_FIELD(arg1, s16 *, 0x810)], 2, 0xF, 0xA);
            func_8013F090(M2C_FIELD(arg0, f32 *, 0x94), 0xB4, 0x14, 0x64);
            func_808AC278(arg0);
            func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 1, M2C_FIELD(arg0, f32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x88), M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, 0);
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x124);
            if (temp_a0 != 0) {
                func_800B6564(temp_a0, 0x3C75C28F);
            }
            if (M2C_FIELD(arg0, u8 *, 0x1D4) != 0) {
                M2C_FIELD(arg0, s16 *, 0x1E2) = 0x46;
                func_808AD440(arg0);
                return;
            }
            M2C_FIELD(arg0, s16 *, 0x1E2) = 0x14;
            func_808AD194(arg0);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x2B5) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B5) | 1);
        func_808AD26C(arg0);
        return;
    }
    func_800B8D94(arg0, 0x31D7);
}

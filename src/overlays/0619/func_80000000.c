// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *, s32);                 /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_80BEB3CC(u8 *, s32);                 /* extern */
M2C_UNK func_80BEB4DC(u8 *);                      /* extern */
extern u8 D_801E7E32;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800B6564(arg0, 0x3E99999A);
    M2C_FIELD(arg0, s16 *, 0x194) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xF000) >> 0xC);
    M2C_FIELD(arg0, s8 *, 0x1F) = 0;
    M2C_FIELD(arg0, f32 *, 0xC4) = 25.0f;
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + 10.0f);
    if (M2C_FIELD(arg0, s16 *, 0x194) == 0) {
        M2C_FIELD(arg0, s8 *, 0xB7) = 0;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 9);
        func_80BEB3CC(arg0, arg1);
        return;
    }
    if (!(D_801E7E32 & 0x40)) {
        if (D_801E7E32 & 0x80) {
            func_800BA9E4(arg1 + 0x1CA0, arg1, 1, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, -1);
        }
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
        func_80BEB4DC(arg0);
        return;
    }
    func_800B6490(arg0, arg1);
}

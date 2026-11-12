#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80182BE0(s32);                         /* extern */
M2C_UNK func_80182C08(f32, s32);                    /* extern */
extern f32 D_80980E50;

void func_800013F0(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 2) {
        func_80182C08(D_80980E50, arg4 + 0x260);
        return;
    }
    if ((arg1 == 4) || (arg1 == 6) || (arg1 == 8)) {
        func_80182BE0((u8 *)((s32)arg4 + ((arg1 >> 1) * 0xC)) + 0x254);
    }
}

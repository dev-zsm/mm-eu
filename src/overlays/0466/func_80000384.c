// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B02EC(s32, s32);                    /* extern */
M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_800E1C28(s32, u8 *);                 /* extern */

void func_80000384(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) < 7) {
        func_800E09D8(arg1, arg0 + 0x494);
        func_800E09D8(arg1, arg0 + 0x4F4);
        func_800E1C28(arg1, arg0 + 0x554);
    }
    func_800B02EC(arg1, M2C_FIELD(arg0, s32 *, 0x5D8));
}

#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1E0]; s16 unk1E0; } S_arg4;

M2C_UNK func_8018132C(f32, f32, f32, M2C_UNK); /* extern */
M2C_UNK func_80182BE0(u8 *);                      /* extern */

void func_800019B0(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, S_arg4 *arg4) {
    if (arg4->unk1E0 < 0xA) {
        if (arg1 == 2) {
            func_8018132C(0, 0, 0, 1);
            func_80182BE0((u8 *)arg4 + 0x270);
        }
        func_80182BE0((u8 *)arg4 + (arg1 * 0xC) + 0x234);
    }
}

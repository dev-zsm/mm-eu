#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x24]; s32 unk24; u8 pad28[0x4]; s32 unk2C; u8 pad30[0x62]; s16 unk92; u8 pad94[0x4]; f32 unk98; f32 unk9C; } S_arg0;
typedef struct { u8 pad0[0x1CCC]; void *unk1CCC; } S_arg1;
typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x4]; f32 unk2C; } S_sp30;

f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
f32 func_8017B8E4(f32, f32, s32, s32);              /* extern */

s32 func_80000634(S_arg0 *arg0, S_arg1 *arg1) {
    S_arg1 *this = arg1;
    S_sp30 *sp30;
    s16 temp_a0;
    s16 sp2E;
    if (arg0->unk98 < 32.0f) {
        if ((arg0->unk9C > -10.0f) && (arg0->unk9C < 31.0f)) {
            sp30 = this->unk1CCC;
            temp_a0 = arg0->unk92 + 0x8000;
            sp2E = temp_a0;
            if (func_8017B8E4(((func_800FEB84(temp_a0)) * 16.0f) + sp30->unk24, (func_800FEB44(temp_a0) * 16.0f) + sp30->unk2C, arg0->unk24, arg0->unk2C) < 400.0f) {
                return 1;
            }
        }
    }
    return 0;
}

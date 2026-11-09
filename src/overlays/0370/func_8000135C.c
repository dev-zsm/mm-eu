#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x13C]; s32 unk13C; u8 pad140[0x92]; s16 unk1D2; u8 pad1D4[0x6]; s16 unk1DA; f32 unk1DC; } S_arg0;

M2C_UNK func_800E26E8(s32, s32, u8 *, u8 *);    /* extern */

void func_8000135C(S_arg0 *arg0, s32 arg1) {
    arg0->unk1DA = (s16) (s32) ((f32) arg0->unk1D2 * arg0->unk1DC);
    if (arg0->unk13C != 0) {
        func_800E26E8(arg1, arg1 + 0x18884, (u8 *)arg0 + 0x18C, arg0);
    }
}

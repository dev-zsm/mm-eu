// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800AEE50(s32, s32, u8 *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_800AF464(s32);                         /* extern */
s32 func_800AFC40(s32);                             /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
extern f32 D_80BDA7B0;

s32 func_8000084C(u8 *arg0, s32 arg1) {
    if ((M2C_FIELD(arg0, u16 *, 0x90) & 1) && (D_80BDA7B0 <= M2C_FIELD(arg0, f32 *, 0x70))) {
        func_800B8C4C(arg0, 0x30F0);
        func_800AEE50(arg1 + 0x830, func_800AFC40(M2C_FIELD(arg0, s32 *, 0x340)), arg0 + 0x24, 0x41900000, (s32) M2C_FIELD(arg0, s16 *, 0xBE), M2C_FIELD(arg0, s32 *, 0x80), (s32) M2C_FIELD(arg0, u8 *, 0x85));
    } else {
        func_800AF464(func_800AFC40(M2C_FIELD(arg0, s32 *, 0x340)));
    }
    return 0;
}

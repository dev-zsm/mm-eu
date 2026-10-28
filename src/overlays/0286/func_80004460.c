// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_809C817C(u8 *, s32);                 /* extern */
M2C_UNK func_809CB324(u8 *, s32);                 /* extern */
extern f32 D_809CDFD0;

void func_80004460(u8 *arg0, s32 arg1) {
    u8 temp_v0;

    M2C_FIELD(arg0, s16 *, 0x25C) = 0xF;
    func_80137070(arg0 + 0x148);
    func_800FFDD8(arg0 + 0x2A8, (s16) (s32) ((func_800FEB84((s16) (M2C_FIELD(arg0, s16 *, 0x240) << 0xD)) * D_809CDFD0) + 12288.0f), 2, 0x3000);
    func_800FFBF8(arg0 + 0x28, 0x43480000, 0x3D4CCCCD, 0x41200000);
    if (M2C_FIELD(arg0, s16 *, 0x24C) == 0) {
        if (M2C_FIELD(arg0, s8 *, 0xB7) < 6) {
            temp_v0 = M2C_FIELD(arg0, u8 *, 0x253);
            if (temp_v0 == 0) {
                M2C_FIELD(arg0, u8 *, 0x253) = (u8) (temp_v0 + 1);
                func_809CB324(arg0, arg1);
                return;
            }
        }
        func_809C817C(arg0, arg1);
        M2C_FIELD(arg0, s16 *, 0x24E) = 0x64;
    }
}

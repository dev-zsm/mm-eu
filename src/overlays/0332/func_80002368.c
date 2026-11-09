#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x32]; s16 unk32; u8 pad34[0x37C]; s16 unk3B0; u8 pad3B2[0xE]; s16 unk3C0; s16 unk3C2; u8 pad3C4[0x37C]; s32 unk740; u8 pad744[0x8]; s16 unk74C; } S_arg0;

M2C_UNK func_800B5B64(s32, s16);                    /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800F0308(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A2AA38(u8 *, s32);                 /* extern */

void func_80002368(S_arg0 *arg0, s32 arg1) {
    s16 temp_a1;
    s32 var_s0;
    u8 *var_s1;

    arg0->unk32 = (s16) (arg0->unk32 + arg0->unk3C0);
    func_800FFCBC((u8 *)arg0 + 0x3C0, 0, 0xA, 0xBB8, 0x14);
    if (arg0->unk3C0 < 0x1E) {
        func_800FFCBC((u8 *)arg0 + 0x3C2, 0, 0xA, 0x1E, 0x14);
        var_s0 = 0;
        var_s1 = (u8 *)arg0 + 0x7F2;
        if (arg0->unk740 > 0) {
            do {
                func_800FFCBC(var_s1, 0, 0xA, 0x1E, 0x14);
                var_s0 += 1;
                var_s1 += 2;
            } while (var_s0 < arg0->unk740);
        }
        arg0->unk3B0 = 6;
    }
    if (arg0->unk3C2 < 0x1E) {
        func_80A2AA38(arg0, arg1);
        func_800F0308(arg1, (u8 *)arg0 + 0x24, 0x32, 0x3878);
        func_800B6490(arg0);
        temp_a1 = arg0->unk74C;
        if (temp_a1 >= 0) {
            func_800B5B64(arg1, temp_a1);
        }
    }
}

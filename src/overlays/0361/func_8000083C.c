#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0xC]; s16 unk1C; u8 pad1E[0xA]; f32 unk28; u8 pad2C[0x134]; f32 unk160; u8 pad164[0xC]; s32 unk170; } S_arg0;
typedef struct { u8 pad0[0x18845]; s8 unk18845; } S_arg1;

s32 func_800B5B20(u8 *, s32);                     /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
s32 func_800FEE3C(u8 *, f32, M2C_UNK);        /* extern */
M2C_UNK func_8016B164(u8 *);                      /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_80A55914(u8 *, u8 *);              /* extern */
M2C_UNK func_80A55D04(u8 *, u8 *);              /* extern */

void func_8000083C(S_arg0 *arg0, S_arg1 *arg1) {
    arg0->unk28 = (f32) (arg0->unkC + arg0->unk160);
    func_80A55914(arg0, arg1);
    if (func_800FEE3C((u8 *)arg0 + 0x160, 0, 0x3F800000) != 0) {
        if (!(arg0->unk170 & 2) && (func_800B5B20(arg1, (((s16) arg0->unk1C >> 4) & 0x7F) + 1) == 0)) {
            arg1->unk18845 = 1;
            func_8016B164(arg1);
            func_8019FF78(0x5801);
        }
        func_80A55D04(arg0, arg1);
        return;
    }
    func_800B8D94(arg0, 0x21C3);
}

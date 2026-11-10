#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x188]; void *unk188; u8 pad18C[0xA4]; u16 unk230; u8 pad232[0x12]; s16 unk244; u8 pad246[0x250]; u16 unk496; s16 unk498; } S_arg0;
typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;

M2C_UNK func_800F1D6C(s16);                         /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151DF4(u8 *, s32, u8 *);         /* extern */
s32 func_801529DC(s32);                             /* extern */
u16 func_80B96470(u8 *);                          /* extern */
extern M2C_UNK D_80B9821C;

void func_80001384(S_arg0 *arg0, S_arg1 *arg1) {
    u16 temp_v0;

    if ((func_801529DC((u8 *)arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        if (arg0->unk496 == 0xD65) {
            func_800F1D6C(arg0->unk498);
            arg0->unk230 = (u16) (arg0->unk230 & 0xFFEF);
            arg0->unk244 = 0x41;
            arg1->unk1682E = 0x43;
            arg1->unk1692F = 4;
            arg0->unk188 = &D_80B9821C;
            return;
        }
        temp_v0 = func_80B96470(arg0);
        arg0->unk496 = temp_v0;
        func_80151DF4(arg1, temp_v0 & 0xFFFF, arg0);
    }
}

#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x148]; void *unk148; u8 pad14C[0x98]; u16 unk1E4; u8 pad1E6[0x2]; u16 unk1E8; u8 pad1EA[0x26C]; s16 unk456; s16 unk458; } S_arg0;
typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;

M2C_UNK func_800F1944(s16);                         /* extern */
M2C_UNK func_800F1D6C(s16);                         /* extern */
s32 func_80147B34(u8 *);                          /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B90114(u8 *, u8 *);              /* extern */
extern M2C_UNK D_80B91FD0;
extern M2C_UNK D_80B92120;

void func_80002BE4(S_arg0 *arg0, S_arg1 *arg1) {
    if ((func_801529DC((u8 *)arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        if (arg0->unk1E8 == 0x2A30) {
            func_800F1D6C(arg0->unk456);
            func_800F1944(arg0->unk458);
            arg0->unk148 = &D_80B91FD0;
        } else {
            func_800F1D6C(arg0->unk458);
            arg1->unk1682E = 0x43;
            arg1->unk1692F = 4;
            arg0->unk1E4 = (u16) (arg0->unk1E4 | 0x40);
            arg0->unk148 = &D_80B92120;
        }
    }
    func_80B90114(arg0, arg1);
}

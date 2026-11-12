#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;
typedef struct { u8 pad0[0x39E]; s16 unk39E; s16 unk3A0; u8 pad3A2[0x4]; s16 unk3A6; } S_arg0;

M2C_UNK func_800B8364(); /* extern */
M2C_UNK func_800F1944();                         /* extern */
M2C_UNK func_800F1D6C();                     /* extern */
s32 func_800F1E2C();                                /* extern */
s32 func_80147B34();                          /* extern */
s32 func_801529DC();                             /* extern */
M2C_UNK func_809F15DC();           /* extern */
extern M2C_UNK D_809F2D00;

void func_800022E8(S_arg0 *arg0, S_arg1 *arg1) {
    if ((func_801529DC((u8 *)arg1 + 0x4908) == 6) && (func_80147B34(arg1) != 0)) {
        arg1->unk1682E = 0x43;
        arg1->unk1692F = 4;
        func_809F15DC(arg0, &D_809F2D00);
        if (arg0->unk39E == 0) {
            if (func_800F1E2C() == 0x7C) {
                func_800F1D6C(0x7C);
            }
            arg0->unk3A0 = (s16) arg0->unk3A6;
            func_800F1944(arg0->unk3A0);
        }
        func_800B8364(arg0, arg1, 0x43C80000, -1);
    }
}

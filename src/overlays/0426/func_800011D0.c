#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;
typedef struct { u8 pad0[0x2D8]; void *unk2D8; u8 pad2DC[0x70]; s16 unk34C; } S_arg0;

s32 func_80147B34(u8 *);                          /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_80ABFE08;
extern M2C_UNK D_80AC0274;

void func_800011D0(S_arg0 *arg0, S_arg1 *arg1) {
    if ((func_801529DC((u8 *)arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        arg1->unk1682E = 0x43;
        arg1->unk1692F = 4;
        if (arg0->unk34C == 0) {
            arg0->unk2D8 = &D_80AC0274;
            return;
        }
        arg0->unk2D8 = &D_80ABFE08;
    }
}

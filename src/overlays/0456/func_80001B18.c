#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x218]; void *unk218; u8 pad21C[0x50]; u16 unk26C; s16 unk26E; } S_arg0;
typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;

s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151DF4(u8 *, s32, u8 *);         /* extern */
s32 func_801529DC(s32);                             /* extern */
s16 func_80AF46AC(u8 *);                          /* extern */
extern M2C_UNK D_80AF5778;

void func_80001B18(S_arg0 *arg0, S_arg1 *arg1) {
    s16 temp_v0;

    if ((func_801529DC((u8 *)arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        if (arg0->unk26C & 2) {
            arg1->unk1682E = 0x43;
            arg1->unk1692F = 4;
            arg0->unk26C = (u16) (arg0->unk26C & 0xFFFD);
            arg0->unk218 = &D_80AF5778;
            return;
        }
        temp_v0 = func_80AF46AC(arg0);
        arg0->unk26E = temp_v0;
        func_80151DF4(arg1, temp_v0 & 0xFFFF, arg0);
    }
}

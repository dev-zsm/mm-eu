#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1DC]; void *unk1DC; u8 pad1E0[0x1EC]; u16 unk3CC; u16 unk3CE; } S_arg0;
typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;

s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151DF4(u8 *, s32, u8 *);         /* extern */
s32 func_801529DC(s32);                             /* extern */
u16 func_80B59B8C(u8 *);                          /* extern */
extern M2C_UNK D_80B58DBC;

void func_800006A4(S_arg0 *arg0, S_arg1 *arg1) {
    u16 temp_v0;
    u16 temp_v0_2;

    if ((func_801529DC((u8 *)arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        temp_v0 = arg0->unk3CE;
        if ((temp_v0 == 0xDCC) || (temp_v0 == 0xDDD) || (temp_v0 == 0xDE0)) {
            arg1->unk1682E = 0x43;
            arg1->unk1692F = 4;
            arg0->unk3CC = (u16) (arg0->unk3CC & 0xFFFB);
            arg0->unk1DC = &D_80B58DBC;
            return;
        }
        temp_v0_2 = func_80B59B8C(arg0);
        arg0->unk3CE = temp_v0_2;
        func_80151DF4(arg1, temp_v0_2 & 0xFFFF, arg0);
    }
}

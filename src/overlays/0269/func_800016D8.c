#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x2D2]; u16 unk2D2; } S_arg0;
typedef struct { u8 pad0[0x18875]; s8 unk18875; u8 pad18876[0x4]; s16 unk1887A; u8 pad1887C[0x3]; s8 unk1887F; } S_arg1;

s32 func_801A9910();                 /* extern */
s32 func_809A7314();                                /* extern */
extern M2C_UNK D_801E6EF0;

void func_800016D8(S_arg0 *arg0, S_arg1 *arg1) {
    arg0->unk2D2 = (u16) (arg0->unk2D2 | 0x20);
    if ((func_809A7314(arg0, arg1) != 0) && (func_801A9910(0, arg1) != 0x41)) {
        arg1->unk1887A = 0x7C10;
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100C) = (u8) ((M2C_FIELD(&D_801E6EF0, u8 *, 0x100C) & 0xF8) | 3);
        arg1->unk1887F = 0x40;
        M2C_FIELD(&D_801E6EF0, s8 *, 0x3F55) = 3;
        arg1->unk18875 = 0x14;
    }
}

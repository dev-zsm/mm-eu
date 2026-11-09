#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1D4]; void *unk1D4; void *unk1D8; u8 pad1DC[0x19D]; u8 unk379; u8 pad37A[0x4F]; s8 unk3C9; u8 pad3CA[0x36]; s32 unk400; u8 pad404[0x34]; s32 unk438; } S_arg0;

M2C_UNK func_80151E7C(s32, u16);                    /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
s32 func_80AC68A0(s32);                             /* extern */
s32 func_80AC7304(u8 *, s32);                     /* extern */
extern M2C_UNK D_80AC920C;

s32 func_80000D40(S_arg0 *arg0, s32 arg1) {
    u8 *temp_v0;

    if (func_80AC7304(arg0, arg1) != 0) {
        return 1;
    }
    if (func_80AC68A0(arg1) != 0) {
        temp_v0 = (u8 *)arg0 + (arg0->unk379 * 4);
        if (M2C_FIELD(M2C_FIELD(temp_v0, u8 **, 0x390), s16 *, 0x1A0) == 0) {
            arg0->unk1D8 = (M2C_UNK *) arg0->unk1D4;
            func_80151E7C(arg1, M2C_FIELD(M2C_FIELD(temp_v0, u8 **, 0x390), u16 *, 0x198));
            func_8019FF78(0x4808);
            arg0->unk400 = 0;
            arg0->unk438 = 0;
            arg0->unk3C9 = 0;
            arg0->unk1D4 = &D_80AC920C;
            return 1;
        }
        func_8019FF78(0x4806);
        return 1;
    }
    return 0;
}

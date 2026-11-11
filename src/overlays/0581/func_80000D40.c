#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x32]; s16 unk32; u8 pad34[0x8A]; s16 unkBE; u8 padC0[0x114]; void *unk1D4; u8 pad1D8[0x4]; s32 unk1DC; s32 unk1E0; s32 unk1E4; } S_arg0;

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_800FF34C(M2C_UNK *, s32);              /* extern */
s16 func_800FF860(M2C_UNK *, M2C_UNK *);            /* extern */
extern M2C_UNK D_80BBDE3C;
extern M2C_UNK D_80BBF258;

void func_80000D40(S_arg0 *arg0) {
    M2C_UNK *sp24;
    M2C_UNK *temp_a0;
    M2C_UNK sp2C;
    s16 temp_v0_2;
    temp_a0 = (u8 *)arg0 + 0x24;
    arg0->unk1E0 = (s32) (arg0->unk1E4 - 1);
    sp24 = temp_a0;
    func_800FF34C(temp_a0, (arg0->unk1DC + (arg0->unk1E4 * 6)) - 6);
    func_800FF34C(&sp2C, (arg0->unk1DC + (arg0->unk1E4 * 6)) - 0xC);
    temp_v0_2 = func_800FF860(&sp2C, sp24);
    arg0->unkBE = temp_v0_2;
    arg0->unk32 = temp_v0_2;
    func_800BD9E0((u8 *)arg0 + 0x190, &D_80BBF258, 3);
    arg0->unk1D4 = &D_80BBDE3C;
}

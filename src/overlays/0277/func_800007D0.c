#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1C]; s16 unk1C; u8 pad1E[0x3A]; f32 unk58; u8 pad5C[0x64]; s16 unkC0; u8 padC2[0x58]; u16 unk11A; s8 unk11C; u8 pad11D[0x3]; void *unk120; u8 pad124[0xA0]; s16 unk1C4; } S_arg0;
typedef struct { u8 pad0[0x274]; s16 unk274; u8 pad276[0x4]; s16 unk27A; } S_temp_v1;

M2C_UNK func_800B3550(); /* extern */
M2C_UNK func_800FEC70();    /* extern */
M2C_UNK func_800FEE3C(s32, f32, s32);    /* extern */
M2C_UNK func_809AF304();                      /* extern */
extern M2C_UNK D_809AFD80;
extern f32 D_809AFE24;

void func_800007D0(S_arg0 *arg0, s32 arg1) {
    S_temp_v1 *temp_v1;

    temp_v1 = arg0->unk120;
    func_800FEE3C((u8 *)arg0 + 0x70, 0, 0x3F000000);
    arg0->unk11C = 0x28;
    if (arg0->unk11A & 0x4000) {
        func_800FEC70((u8 *)arg0 + 0xBC, 0x4000, 0x200);
        arg0->unkC0 = (s16) (arg0->unkC0 + 0x1780);
    }
    if (arg0->unk1C4 >= 0x15) {
        func_800B3550(arg1, (u8 *)arg0 + 0x24, &D_809AFD80, &D_809AFD80, (s32) (arg0->unk58 * D_809AFE24), 0, 0);
        temp_v1->unk27A = (s16) (temp_v1->unk27A + 1);
        temp_v1->unk274 = (s16) (temp_v1->unk274 & ~(1 << ((s32) (arg0->unk1C & 0xFF00) >> 8)));
        func_809AF304(arg0);
    }
    arg0->unk1C4 = (s16) (arg0->unk1C4 + 1);
}

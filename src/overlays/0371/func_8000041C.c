#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1CCC]; void *unk1CCC; u8 pad1CD0[0x14B5E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; u8 pad16930[0x2DA]; s16 unk16C0A; s16 unk16C0C; } S_arg0;
typedef struct { u8 pad0[0x116]; s16 unk116; u8 pad118[0x2C]; void *unk144; u8 pad148[0x1EA]; s16 unk332; s16 unk334; u8 pad336[0x4E]; s32 unk384; u8 pad388[0x34]; s32 unk3BC; u8 pad3C0[0x1C]; void *unk3DC; s16 unk3E0; u8 pad3E2[0x1E]; s8 unk400; u8 pad401[0x1]; s16 unk402; u8 pad404[0x2]; s16 unk406; u8 pad408[0x24]; u16 unk42C; } S_arg1;
typedef struct { u8 pad0[0xA70]; s32 unkA70; } S_sp24;

M2C_UNK func_800B8254(u8 *, u8 *);              /* extern */
M2C_UNK func_800F1D6C(s16);                         /* extern */
M2C_UNK func_8010EE64(M2C_UNK);                     /* extern */
extern M2C_UNK D_80A71D14;
extern M2C_UNK D_80A734B0;

void func_8000041C(S_arg0 *arg0, S_arg1 *arg1) {
    S_sp24 *sp24;

    sp24 = arg0->unk1CCC;
    if (arg1->unk334 == 3) {
        func_800F1D6C(arg1->unk3E0);
        arg1->unk334 = 0;
    }
    func_800B8254(arg1, arg0);
    arg0->unk1682E = 0x43;
    arg0->unk1692F = 4;
    func_8010EE64(0x32);
    arg1->unk400 = 0;
    arg1->unk384 = 0;
    arg1->unk3BC = 0;
    sp24->unkA70 = (s32) (sp24->unkA70 & 0xDFFFFFFF);
    arg0->unk16C0A = 0;
    arg0->unk16C0C = 0;
    arg1->unk406 = 0x834;
    arg1->unk402 = 0x50;
    arg1->unk42C = (u16) (arg1->unk42C | 1);
    arg1->unk332 = 0xA;
    arg1->unk116 = 0;
    arg1->unk144 = &D_80A71D14;
    arg1->unk3DC = &D_80A734B0;
}

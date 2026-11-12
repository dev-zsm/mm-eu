#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1CCC]; void *unk1CCC; u8 pad1CD0[0x14B5E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; u8 pad16930[0x2DA]; s16 unk16C0A; s16 unk16C0C; } S_arg0;
typedef struct { u8 pad0[0x321]; s8 unk321; u8 pad322[0x36]; s32 unk358; u8 pad35C[0x34]; s32 unk390; u8 pad394[0xA]; s16 unk39E; s16 unk3A0; } S_arg1;
typedef struct { u8 pad0[0xA70]; s32 unkA70; } S_sp24;

M2C_UNK func_800B8254();              /* extern */
M2C_UNK func_800F1D6C();                         /* extern */
M2C_UNK func_8010EE64();                     /* extern */
M2C_UNK func_809F15DC();           /* extern */
extern M2C_UNK D_809F21D0;

void func_800008A8(S_arg0 *arg0, S_arg1 *arg1) {
    S_sp24 *sp24;

    sp24 = arg0->unk1CCC;
    if (arg1->unk39E == 2) {
        func_800F1D6C(arg1->unk3A0);
        arg1->unk39E = 0;
    }
    func_800B8254(arg1, arg0);
    arg0->unk1682E = 0x43;
    arg0->unk1692F = 4;
    func_8010EE64(0x32);
    arg1->unk321 = 0;
    arg1->unk358 = 0;
    arg1->unk390 = 0;
    sp24->unkA70 = (s32) (sp24->unkA70 & 0xDFFFFFFF);
    arg0->unk16C0A = 0;
    arg0->unk16C0C = 0;
    func_809F15DC(arg1, &D_809F21D0);
}

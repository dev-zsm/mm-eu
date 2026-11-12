#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0x13C]; void *unk144; u8 pad148[0x14]; s16 unk15C; u8 pad15E[0x76]; f32 unk1D4; u8 pad1D8[0xA9F0]; s32 unkABC8; u8 padABCC[0x4]; s16 unkABD0; } S_arg0;

s32 func_80134AE8();                       /* extern */
M2C_UNK func_80137828();  /* extern */
M2C_UNK func_809D9CDC();                     /* extern */
extern M2C_UNK D_6000D0C;
extern M2C_UNK D_809E3464;

void func_80009D30(S_arg0 *arg0, M2C_UNK arg1) {
    arg0->unk144 = &D_809E3464;
    func_809D9CDC(arg1);
    func_80137828((u8 *)arg0 + 0x190, &D_6000D0C, 0xC0000000);
    arg0->unk1D4 = (f32) func_80134AE8(&D_6000D0C);
    arg0->unkABD0 = 0;
    arg0->unkABC8 = 0;
    arg0->unk4 = (s32) (arg0->unk4 & ~1);
    arg0->unk15C = 0x14;
}

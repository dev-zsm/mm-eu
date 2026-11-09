#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x116]; s16 unk116; u8 pad118[0xBC]; void *unk1D4; u8 pad1D8[0x190]; s16 unk368; s16 unk36A; u8 pad36C[0x5D]; s8 unk3C9; u8 pad3CA[0x36]; s32 unk400; u8 pad404[0x34]; s32 unk438; } S_arg0;
typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; u8 pad16930[0x2DA]; s16 unk16C0A; s16 unk16C0C; } S_arg1;

M2C_UNK func_800B8254(u8 *, u8 *);              /* extern */
M2C_UNK func_800F1D6C(s16);                         /* extern */
M2C_UNK func_8010EE64(M2C_UNK);                     /* extern */
extern M2C_UNK D_80AC7E28;

void func_800009B4(S_arg0 *arg0, S_arg1 *arg1) {
    if (arg0->unk368 == 2) {
        func_800F1D6C(arg0->unk36A);
        arg0->unk368 = 0;
    }
    func_800B8254(arg0, arg1);
    arg1->unk1682E = 0x43;
    arg1->unk1692F = 4;
    func_8010EE64(0x32);
    arg0->unk3C9 = 0;
    arg0->unk400 = 0;
    arg0->unk438 = 0;
    arg1->unk16C0A = 0;
    arg1->unk16C0C = 0;
    arg0->unk116 = 0;
    arg0->unk1D4 = &D_80AC7E28;
}

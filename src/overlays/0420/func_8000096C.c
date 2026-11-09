#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x3A8]; u16 unk3A8; u8 pad3AA[0x8]; s16 unk3B2; u8 pad3B4[0x24]; u8 unk3D8; } S_arg0;
typedef struct { u8 pad0[0x1682E]; s8 unk1682E; u8 pad1682F[0x100]; s8 unk1692F; } S_arg1;

s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151DF4(u8 *, u16, u8 *);         /* extern */
u8 func_801529DC(s32);                              /* extern */
M2C_UNK func_80AB80B0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_80AB9428(u8 *);                      /* extern */
extern M2C_UNK D_80ABA510;

void func_8000096C(S_arg0 *arg0, S_arg1 *arg1) {
    u8 sp27;

    sp27 = func_801529DC((u8 *)arg1 + 0x4908);
    func_80AB9428(arg0);
    if (arg0->unk3D8 != 0) {
        func_80151DF4(arg1, arg0->unk3A8, arg0);
        arg0->unk3D8 = 0U;
        return;
    }
    if ((sp27 == 5) && (func_80147B34(arg1) != 0)) {
        arg1->unk1682E = 0x43;
        arg1->unk1692F = 4;
        func_80AB80B0((u8 *)arg0 + 0x150, &D_80ABA510, 6);
        arg0->unk3B2 = 4;
    }
}

// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0478.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
s32 func_800C9F3C(s32, s32, s32, s32, f32 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80B16A94(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80B178E8;

void func_800016A4(Actor *thisx, PlayState *play) {
    M2C_UNK sp34;
    f32 sp30;
    s32 pad;

    func_800B680C(thisx);
    func_800FF30C((u8 *)thisx + 0x3C, (u8 *)thisx + 0x24);
    M2C_FIELD(thisx, f32 *, 0x40) = (f32) (M2C_FIELD(thisx, f32 *, 0x40) + 10.0f);
    sp30 = M2C_FIELD(thisx, f32 *, 0x28);
    if (func_800C9F3C(play, (u8 *)play + 0x830, M2C_FIELD(thisx, s32 *, 0x24), M2C_FIELD(thisx, s32 *, 0x2C), &sp30, &sp34) != 0) {
        if ((M2C_FIELD(thisx, f32 *, 0x28) + 50.0f) < sp30) {
            M2C_FIELD(thisx, M2C_UNK **, 0x1F8) = &D_80B178E8;
        }
        func_80B16A94(thisx, play, 0, 0xC1A00000);
        func_80B16A94(thisx, play, 0, 0xC1A00000);
    }
}

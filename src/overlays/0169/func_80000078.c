#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0169.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(u8 *, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(u8 *, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80937740(u8 *, u8 *);              /* extern */
extern M2C_UNK D_60005C0;
extern M2C_UNK D_6006260;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80937F4C;
extern M2C_UNK D_80938400;

void func_80000078(Actor *thisx, PlayState *play) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x42100000);
    temp_a1 = (u8 *)thisx + 0x190;
    sp34 = temp_a1;
    func_80136ED0(play, temp_a1, &D_6006260, &D_60005C0, (u8 *)thisx + 0x1D4, (u8 *)thisx + 0x234, 0x10);
    func_801378E0(sp34, &D_60005C0);
    func_800E1134(play, (u8 *)thisx + 0x144, thisx, &D_80938400);
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, M2C_UNK **, 0x394) = &D_80937F4C;
    if (M2C_FIELD(play, u8 *, 0x18B48) == 1) {
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x10000);
    }
    M2C_FIELD(thisx, s16 *, 0x2A0) = 0;
    M2C_FIELD(thisx, s8 *, 0x1F) = 6;
    func_80937740(thisx, play);
}

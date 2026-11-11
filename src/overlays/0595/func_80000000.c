#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0595.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80BCCB54(u8 *);                      /* extern */
extern M2C_UNK D_6000E50;
extern M2C_UNK D_6007150;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BCD1BC;

void func_80000000(Actor *thisx, PlayState *play) {
    s16 temp_v0;

    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    func_800B3B14((u8 *)thisx + 0xBC, 0.0f, &D_800B3F30, 0x42200000);
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_6007150, &D_6000E50, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1EE, 0x11);
    temp_v0 = M2C_FIELD(thisx, s16 *, 0x1C);
    M2C_FIELD(thisx, s32 *, 0x280) = (s32) temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(thisx, s32 *, 0x284) = 1;
        M2C_FIELD(thisx, s16 *, 0x27A) = 2;
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF34) & 0x80) {
            M2C_FIELD(thisx, s16 *, 0x27A) = 3;
        }
        if ((M2C_FIELD(&D_801E6EF0, s32 *, 0x18) != 3) || (M2C_FIELD(&D_801E6EF0, s32 *, 0x10) == 0)) {
            func_800B6490(thisx);
        }
    } else {
        M2C_FIELD(thisx, s16 *, 0x2D4) = 0x1E;
        M2C_FIELD(thisx, s16 *, 0x2D6) = 0x3C;
        M2C_FIELD(thisx, s16 *, 0x2D8) = 0;
        if ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) & 0x80) || ((M2C_FIELD(&D_801E6EF0, s32 *, 0x18) == 3) && (M2C_FIELD(&D_801E6EF0, s32 *, 0x10) != 0))) {
            func_800B6490(thisx);
        }
    }
    M2C_FIELD(thisx, s8 *, 0x1F) = 6;
    M2C_FIELD(thisx, f32 *, 0x74) = -3.0f;
    func_800E1134(play, (u8 *)thisx + 0x294, thisx, &D_80BCD1BC);
    func_80BCCB54(thisx);
}

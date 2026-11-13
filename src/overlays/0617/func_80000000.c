#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0617.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80BE98E0(u8 *);                      /* extern */
extern M2C_UNK D_60064B8;
extern M2C_UNK D_600F82C;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BEA650;

void func_80000000(Actor *thisx, PlayState *play) {
    f32 temp_f6;

    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    func_800B3B14((u8 *)thisx + 0xBC, 0.0f, &D_800B3F30, 0x41980000);
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_600F82C, &D_60064B8, (u8 *)thisx + 0x188, (u8 *)thisx + 0x206, 0x15);
    M2C_FIELD(thisx, s8 *, 0x1F) = 6;
    func_800E1134(play, (u8 *)thisx + 0x2D0, thisx, &D_80BEA650);
    if ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF41) & 0x80) || (M2C_FIELD(&D_801E6EF0, s32 *, 0) == 0xD220)) {
        M2C_FIELD(thisx, f32 *, 0x24) = (f32) ((func_800FEB84((s16) (M2C_FIELD(thisx, s16 *, 0x16) + 0xC100)) * 50.0f) + M2C_FIELD(thisx, f32 *, 0x24));
        temp_f6 = func_800FEB44((s16) (M2C_FIELD(thisx, s16 *, 0x16) + 0xC100)) * 50.0f;
        M2C_FIELD(thisx, s8 *, 0x2AC) = 1;
        M2C_FIELD(thisx, f32 *, 0x2C) = (f32) (M2C_FIELD(thisx, f32 *, 0x2C) + temp_f6);
    }
    M2C_FIELD(thisx, s16 *, 0x2B0) = (s16) M2C_FIELD(thisx, s8 *, 0x38);
    if (M2C_FIELD(thisx, s16 *, 0x2B0) == 0) {
        func_800B6490(thisx);
    }
    func_80BE98E0(thisx);
}

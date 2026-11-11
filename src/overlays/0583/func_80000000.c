#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0583.h"

M2C_UNK func_800B3B14(s32, f32, s32, s32); /* extern */
s32 func_800B5B20();                        /* extern */
M2C_UNK func_800B6490();                 /* extern */
M2C_UNK func_800B6564();             /* extern */
M2C_UNK func_800E1134(); /* extern */
M2C_UNK func_80136E1C(); /* extern */
s32 func_8013D9F8();               /* extern */
M2C_UNK func_801A5F50();                     /* extern */
M2C_UNK func_80BC0008();                      /* extern */
extern M2C_UNK D_60023B8;
extern M2C_UNK D_60024CC;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BC0E70;

void func_80000000(Actor *thisx, PlayState *play) {
    s16 temp_a1;
    s16 temp_v1;

    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136E1C(play, (u8 *)thisx + 0x144, &D_60023B8, &D_60024CC, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1C4, 0xA);
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(thisx, s8 *, 0x1F) = 0;
    func_800E1134(play, (u8 *)thisx + 0x234, thisx, &D_80BC0E70);
    temp_v1 = M2C_FIELD(thisx, s16 *, 0x1C);
    M2C_FIELD(thisx, s16 *, 0x21E) = (s16) ((temp_v1 >> 7) & 0x1F);
    M2C_FIELD(thisx, s16 *, 0x21C) = (s16) (temp_v1 & 0x7F);
    if (M2C_FIELD(thisx, s16 *, 0x21C) == 0x7F) {
        M2C_FIELD(thisx, s16 *, 0x21C) = -1;
    }
    if ((M2C_FIELD(thisx, s16 *, 0x21C) >= 0) && (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x21C)) != 0)) {
        func_800B6490(thisx);
        return;
    }
    temp_a1 = M2C_FIELD(thisx, s16 *, 0x21E);
    if (temp_a1 == 0x1F) {
        func_800B6490(thisx, temp_a1);
        return;
    }
    M2C_FIELD(thisx, s32 *, 0x204) = func_8013D9F8(play, temp_a1, 0x3F);
    M2C_FIELD(thisx, s16 *, 0x226) = (s16) M2C_FIELD(thisx, s8 *, 0x38);
    func_801A5F50(2);
    func_80BC0008(thisx);
}

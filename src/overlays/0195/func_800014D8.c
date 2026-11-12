#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0195.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_8012F5DC(s16);                             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80136E1C(u8 *, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80958C30(u8 *, M2C_UNK *);           /* extern */
s32 func_80958CC4(u8 *);                          /* extern */
M2C_UNK func_80958DC0(u8 *, u8 *);              /* extern */
M2C_UNK func_80958F8C(u8 *, u8 *);              /* extern */
M2C_UNK func_809592FC(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_6000304;
extern M2C_UNK D_6001494;
extern M2C_UNK D_6006470;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_8095A954;

void func_800014D8(Actor *thisx, PlayState *play) {
    f32 sp3C;
    s32 sp30;
    s32 temp_a1;

    sp3C = (f32) func_80134AE8(&D_6000304);
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41F00000);
    temp_a1 = (u8 *)thisx + 0x144;
    sp30 = temp_a1;
    func_80136E1C(play, temp_a1, &D_6006470, 0, (u8 *)thisx + 0x188, (u8 *)thisx + 0x23C, 0x1E);
    func_80137788(sp30, &D_6001494, 0x3F800000, 0.0f, sp3C, 1, 0.0f);
    M2C_FIELD(thisx, s32 *, 0x530) = func_80958CC4(play);
    func_80958F8C(thisx, play);
    M2C_FIELD(thisx, u16 *, 0x5C2) = 0U;
    M2C_FIELD(thisx, s8 *, 0x5C4) = 0;
    func_80958DC0(thisx, play);
    if (!(M2C_FIELD(thisx, s16 *, 0x1C) & 0xF)) {
        M2C_FIELD(thisx, u16 *, 0x5C2) = (u16) (M2C_FIELD(thisx, u16 *, 0x5C2) | 0x20);
    }
    if (!(M2C_FIELD(thisx, u16 *, 0x5C2) & 0x20)) {
        func_809592FC(thisx, 0x3F000000, 0x3F800000);
    } else {
        func_809592FC(thisx, 0x3F400000, 0x3F800000);
    }
    M2C_FIELD(thisx, f32 *, 0x74) = 0.0f;
    M2C_FIELD(thisx, s16 *, 0x51C) = (s16) M2C_FIELD(thisx, s16 *, 0x32);
    func_80958C30(thisx, &D_8095A954);
    if (func_8012F5DC(M2C_FIELD(play, s16 *, 0xA4)) >= 0x1E) {
        func_800B6490(thisx);
    }
}

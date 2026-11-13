#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0102.h"

M2C_UNK func_800B3B14(u8 *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E201C(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136E1C(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_808C17B4(u8 *);                      /* extern */
extern M2C_UNK D_6000444;
extern M2C_UNK D_6001A30;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_808C2E80;
extern M2C_UNK D_808C2EAC;
extern M2C_UNK D_808C2ECC;
extern M2C_UNK D_808C2ED4;
extern f32 D_808C2F00;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 temp_v0;

    func_800FF8DC(thisx, &D_808C2ED4);
    func_80136E1C(play, (u8 *)thisx + 0x144, &D_6001A30, &D_6000444, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1E8, 0x10);
    func_800E201C(play, (u8 *)thisx + 0x2F4, thisx, &D_808C2E80);
    func_800B3B14((u8 *)thisx + 0xBC, 0x44BB8000, &D_800B3F30, 0x420C0000);
    func_800E72F0((u8 *)thisx + 0xA0, &D_808C2EAC, &D_808C2ECC);
    temp_v0 = ((s16) M2C_FIELD(thisx, s16 *, 0x1C) >> 8) & 0xFF;
    M2C_FIELD(thisx, f32 *, 0x268) = (f32) D_808C2F00;
    M2C_FIELD(thisx, f32 *, 0x264) = 1.0f;
    M2C_FIELD(thisx, f32 *, 0x28) = (f32) (M2C_FIELD(thisx, f32 *, 0x28) + 50.0f);
    if (temp_v0 == 0xFF) {
        M2C_FIELD(thisx, f32 *, 0x260) = 200.0f;
    } else {
        M2C_FIELD(thisx, f32 *, 0x260) = (f32) ((f32) temp_v0 * 4.0f);
    }
    func_808C17B4(thisx);
}

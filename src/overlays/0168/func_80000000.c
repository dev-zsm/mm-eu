#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0168.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E1064(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
extern M2C_UNK D_60005EC;
extern M2C_UNK D_6003DC0;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80937224;
extern M2C_UNK D_80937690;
extern M2C_UNK D_809376BC;

void func_80000000(Actor *thisx, PlayState *play) {
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_809376BC);
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_6003DC0, &D_60005EC, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1BE, 9);
    temp_a1 = (u8 *)thisx + 0x1F8;
    func_800E0F5C(play, temp_a1);
    func_800E1064(play, temp_a1, thisx, &D_80937690);
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x420C0000);
    func_800B6564(thisx, 0x3C75C28F);
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(thisx, M2C_UNK **, 0x1F4) = &D_80937224;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    M2C_FIELD(thisx, f32 *, 0x68) = 0.0f;
    M2C_FIELD(thisx, f32 *, 0x74) = -1.0f;
}

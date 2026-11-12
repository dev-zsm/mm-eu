#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0251.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_809868F0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_6013328;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80986A4C;
extern M2C_UNK D_80986CC0;
extern f32 D_80986CF0;

void func_8000009C(Actor *thisx, PlayState *play) {
    u8 *temp_a1;

    M2C_FIELD(thisx, s16 *, 0x2E0) = 0;
    M2C_FIELD(thisx, s32 *, 0x2F0) = 0xFF;
    M2C_FIELD(thisx, f32 *, 0x54) = (f32) D_80986CF0;
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41C00000);
    temp_a1 = (u8 *)thisx + 0x144;
    func_80136ED0(play, temp_a1, &D_6013328, 0, 0, 0, 0);
    func_809868F0(temp_a1, &D_80986CC0, 0);
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, M2C_UNK **, 0x290) = &D_80986A4C;
}

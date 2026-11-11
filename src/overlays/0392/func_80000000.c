#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0392.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80136E1C(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80A9FFCC(u8 *);                      /* extern */
M2C_UNK func_80AA0584(u8 *, s32);                 /* extern */
extern M2C_UNK D_6002848;
extern M2C_UNK D_6002A08;
extern M2C_UNK D_800B3F30;
extern u8 D_801E7DFF;
extern M2C_UNK D_80AA0B20;
extern s32 D_80AA0B4C;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136E1C(play, (u8 *)thisx + 0x144, &D_6002848, &D_6002A08, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1CA, 0xB);
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(thisx, s8 *, 0x1F) = 1;
    func_800E1134(play, (u8 *)thisx + 0x244, thisx, &D_80AA0B20);
    func_800B6564(thisx, 0x3C75C28F);
    func_800FF30C((u8 *)thisx + 0x228, (u8 *)thisx + 0x24);
    M2C_FIELD(thisx, s16 *, 0x21E) = (s16) D_80AA0B4C;
    D_80AA0B4C += 1;
    if (!(D_801E7DFF & 0x20)) {
        func_80A9FFCC(thisx);
        return;
    }
    func_80AA0584(thisx, play);
}

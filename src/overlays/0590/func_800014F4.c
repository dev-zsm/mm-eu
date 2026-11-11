#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0590.h"

M2C_UNK func_800B3B14(u8 *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E090C(s32, u8 *);                 /* extern */
M2C_UNK func_800E0CD4(s32, u8 *, u8 *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
s32 func_8013D9F8(s32, s16, M2C_UNK);               /* extern */
extern M2C_UNK D_60000F0;
extern M2C_UNK D_60010C0;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BC7F18;
extern M2C_UNK D_80BC8774;
extern u8 *D_80BC8780;
extern M2C_UNK D_80BC8784;
extern M2C_UNK D_80BC878C;
extern M2C_UNK D_80BC87AC;

void func_800014F4(Actor *thisx, PlayState *play) {
    s32 temp_v0;
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_80BC87AC);
    func_80136ED0(play, (u8 *)thisx + 0x194, &D_60010C0, &D_60000F0, (u8 *)thisx + 0x1E0, (u8 *)thisx + 0x216, 9);
    func_800B3B14((u8 *)thisx + 0xBC, 0x44FA0000, &D_800B3F30, 0x41A00000);
    temp_a1 = (u8 *)thisx + 0x254;
    func_800E090C(play, temp_a1);
    func_800E0CD4(play, temp_a1, thisx, &D_80BC8774, (u8 *)thisx + 0x274);
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x270), s16 *, 0x36) = (s16) M2C_FIELD(D_80BC8780, s16 *, 0x20);
    func_800E72F0((u8 *)thisx + 0xA0, &D_80BC878C, &D_80BC8784);
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x02000000);
    temp_v0 = func_8013D9F8(play, (s16) ((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0xFC00) >> 0xA), 0x3F);
    M2C_FIELD(thisx, s32 *, 0x24C) = temp_v0;
    if (temp_v0 != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x1D8) = &D_80BC7F18;
        return;
    }
    func_800B6490(thisx);
}

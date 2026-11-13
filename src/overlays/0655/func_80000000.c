#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0655.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6000074;
extern M2C_UNK D_6001E60;
extern M2C_UNK D_80C07B8C;

void func_80000000(Actor *thisx, PlayState *play) {
    u8 *temp_a1;

    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    func_800B6564(thisx, 0x3C23D70A);
    temp_a1 = (u8 *)thisx + 0x144;
    func_80136ED0(play, temp_a1, &D_6001E60, &D_6000074, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1AC, 6);
    func_801378E0(temp_a1, &D_6000074);
    M2C_FIELD(thisx, M2C_UNK **, 0x1E8) = &D_80C07B8C;
}

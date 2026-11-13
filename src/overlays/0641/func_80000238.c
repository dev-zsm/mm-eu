#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0641.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_80BFD930(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600B380;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BFD9F0;

void func_80000238(Actor *thisx, PlayState *play) {
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41600000);
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_600B380, 0, (u8 *)thisx + 0x1B8, (u8 *)thisx + 0x254, 0x1A);
    M2C_FIELD(thisx, s32 *, 0x304) = -1;
    func_80BFD930(thisx, 0);
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    M2C_FIELD(thisx, u16 *, 0x2F0) = (u16) (M2C_FIELD(thisx, u16 *, 0x2F0) | 8);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80BFD9F0;
}

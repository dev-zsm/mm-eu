#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0228.h"

M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_80968BDC(u8 *);                      /* extern */
extern M2C_UNK D_8096A520;
extern M2C_UNK D_8096A54C;
extern M2C_UNK D_8096A554;

void func_80000000(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    func_800E1134(play, (u8 *)thisx + 0x160, thisx, &D_8096A520);
    func_800E72F0((u8 *)thisx + 0xA0, &D_8096A554, &D_8096A54C);
    M2C_FIELD(thisx, s8 *, 0xD0) = 0xFF;
    M2C_FIELD(thisx, s8 *, 0x149) = (s8) M2C_FIELD(thisx, s16 *, 0x1C);
    M2C_FIELD(thisx, u8 *, 0xD0) = 0xFF;
    func_80968BDC(thisx);
}

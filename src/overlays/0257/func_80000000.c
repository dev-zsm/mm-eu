#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0257.h"

M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E10CC(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
extern M2C_UNK D_6000E88;
extern M2C_UNK D_8098AEB0;
extern M2C_UNK D_8098AEDC;

void func_80000000(Actor *thisx, PlayState *play) {
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_8098AEDC);
    temp_a1 = (u8 *)thisx + 0x144;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_8098AEB0);
    func_800E7BB8(thisx, temp_a1);
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(thisx, s32 *, 0x190) = func_80100304(&D_6000E88);
}

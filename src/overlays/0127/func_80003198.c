#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0127.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
s32 func_801244EC(M2C_UNK);                         /* extern */
M2C_UNK func_808F2960(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F29D0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F29F4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F2AD4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F2FB8(u8 *, M2C_UNK);             /* extern */

void func_80003198(Actor *thisx, PlayState *play) {
    s32 temp_v1;

    func_808F29D0(thisx, play);
    func_808F29F4(thisx, play);
    temp_v1 = M2C_FIELD(thisx, s32 *, 0x4AC);
    if (temp_v1 & 2) {
        M2C_FIELD(thisx, s32 *, 0x4AC) = (s32) (temp_v1 & ~2);
        func_808F2FB8(thisx, play);
    }
    if (func_801244EC(play) == 8) {
        M2C_FIELD(thisx, s32 *, 0x4AC) = (s32) (M2C_FIELD(thisx, s32 *, 0x4AC) | 0x40);
    } else {
        M2C_FIELD(thisx, s32 *, 0x4AC) = (s32) (M2C_FIELD(thisx, s32 *, 0x4AC) & ~0x40);
    }
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(thisx, play);
    func_800B763C(play, thisx, 0.0f, 0.0f, 0.0f, 4);
    func_808F2AD4(thisx, play);
    func_808F2960(thisx, play);
}

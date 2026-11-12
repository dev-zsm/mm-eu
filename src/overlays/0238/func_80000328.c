#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0238.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_809745E8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80974668(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80974BE8(M2C_UNK, u8 *, M2C_UNK);    /* extern */

void func_80000328(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(thisx, play);
    func_800B763C(play, thisx, 0.0f, 0.0f, 0.0f, 4);
    func_80974668(thisx, play);
    func_80974BE8(play, (u8 *)thisx + 0x2F0, 0xA);
    func_809745E8(thisx, play);
}

#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0279.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_809AFFC0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809B0134(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809B01D0(u8 *, M2C_UNK);             /* extern */

void func_80000608(Actor *thisx, PlayState *play) {
    func_809B0134(thisx, play);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(thisx, play);
    func_800B763C(play, thisx, 0.0f, 0.0f, 0.0f, 4);
    func_809AFFC0(thisx, play);
    func_809B01D0(thisx, play);
}

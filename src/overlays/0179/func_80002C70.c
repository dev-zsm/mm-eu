#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0179.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_8094686C(M2C_UNK);                     /* extern */
M2C_UNK func_80946B8C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80948B24(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80948BC8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80948DD0(u8 *, M2C_UNK);             /* extern */

void func_80002C70(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x1D4)(thisx, play);
    func_80948DD0(thisx, play);
    func_800B680C(thisx);
    func_80946B8C(thisx, play);
    func_800B763C(play, thisx, 0.0f, 0.0f, 0.0f, 4);
    func_80137070((u8 *)thisx + 0x190);
    func_8094686C(play);
    func_80948BC8(thisx, play);
    func_80948B24(thisx, play);
}

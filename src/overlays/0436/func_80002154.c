#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0436.h"

M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80ACE87C(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80ACE8FC(u8 *, s32);                 /* extern */
M2C_UNK func_80AD0860(u8 *, s32);                 /* extern */

void func_80002154(Actor *thisx, PlayState *play) {
    func_80137070((u8 *)thisx + 0x190);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x1D4)(thisx, play);
    func_80AD0860(thisx, play);
    func_800B763C(play, thisx, 0.0f, 0.0f, 0.0f, 4);
    func_80ACE8FC(thisx, play);
    if (func_80ACE87C(0, 2) != 0) {
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    }
}

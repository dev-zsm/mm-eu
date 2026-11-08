// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0083.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
s32 func_800FED2C(s32, M2C_UNK, M2C_UNK, u8 *);   /* extern */

void EnTorch2_UpdateDeath(Actor *thisx, PlayState *play) {
    if (func_800FED2C((u8 *)thisx + 0x192, 0, 8, thisx) != 0) {
        func_800B6490(thisx);
        return;
    }
    M2C_FIELD(thisx, f32 *, 0x74) = -1.0f;
    func_800B680C(thisx);
}

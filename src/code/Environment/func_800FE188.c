// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Environment_DrawSun(s32);                         /* extern */
M2C_UNK func_800FA9E0(s32);                         /* extern */
M2C_UNK Environment_UpdateLightningStrike(s32);                         /* extern */
M2C_UNK Environment_DrawLightning(s32, M2C_UNK);                /* extern */
M2C_UNK Environment_SetupSkyboxStars(s32);                         /* extern */

void Environment_Draw(struct PlayState *play) {
    Environment_SetupSkyboxStars(play);
    Environment_DrawSun(play);
    Environment_UpdateLightningStrike(play);
    Environment_DrawLightning(play, 0);
    func_800FA9E0(play);
}

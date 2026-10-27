// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Environment_DrawSun(s32);                         /* extern */
M2C_UNK func_800FA9E0(s32);                         /* extern */
M2C_UNK func_800FAE08(s32);                         /* extern */
M2C_UNK Environment_DrawLightning(s32, M2C_UNK);                /* extern */
M2C_UNK Environment_SetupSkyboxStars(s32);                         /* extern */

void Environment_Draw(s32 arg0) {
    Environment_SetupSkyboxStars(arg0);
    Environment_DrawSun(arg0);
    func_800FAE08(arg0);
    Environment_DrawLightning(arg0, 0);
    func_800FA9E0(arg0);
}

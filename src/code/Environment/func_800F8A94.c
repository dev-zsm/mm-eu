// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Environment_WipeRumbleRequests();                            /* extern */
M2C_UNK Environment_UpdateSkyboxRotY(s32);                         /* extern */
M2C_UNK Environment_UpdateNextDayTime();                            /* extern */
M2C_UNK Environment_UpdateTime(s32, s32, void *, s32, s32);  /* extern */
M2C_UNK Environment_UpdateLights(s32, s32, s32);               /* extern */
M2C_UNK Environment_UpdateSun(s32);                         /* extern */
M2C_UNK Environment_UpdatePostmanEvents(s32);                         /* extern */
M2C_UNK Environment_UpdateTimeBasedSequence(s32);                         /* extern */
M2C_UNK Environment_UpdateRain(s32);                         /* extern */
extern s8 D_801BE710;
extern s8 D_801BE714;

void Environment_Update(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5) {
    D_801BE710 = 0;
    D_801BE714 = 0;
    Environment_WipeRumbleRequests();
    if (M2C_FIELD(arg3, u16 *, 0x1EC) == 0) {
        Environment_UpdateSkyboxRotY(arg0);
        Environment_UpdateRain(arg0);
        Environment_UpdateTimeBasedSequence(arg0);
        Environment_UpdateNextDayTime();
        Environment_UpdateTime(arg0, arg1, arg3, arg4, arg5);
        Environment_UpdateSun(arg0);
        Environment_UpdateLights(arg0, arg1, arg2);
        Environment_UpdatePostmanEvents(arg0);
    }
}

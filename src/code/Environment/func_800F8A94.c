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

void Environment_Update(struct PlayState *play, struct EnvironmentContext *envCtx, struct LightContext *lightCtx, struct PauseContext *pauseCtx, struct MessageContext *msgCtx, struct GameOverContext *gameOverCtx, struct GraphicsContext *gfxCtx) {
    D_801BE710 = 0;
    D_801BE714 = 0;
    Environment_WipeRumbleRequests();
    if (M2C_FIELD(pauseCtx, u16 *, 0x1EC) == 0) {
        Environment_UpdateSkyboxRotY(play);
        Environment_UpdateRain(play);
        Environment_UpdateTimeBasedSequence(play);
        Environment_UpdateNextDayTime();
        Environment_UpdateTime(play, envCtx, pauseCtx, msgCtx, gameOverCtx);
        Environment_UpdateSun(play);
        Environment_UpdateLights(play, envCtx, lightCtx);
        Environment_UpdatePostmanEvents(play);
    }
}

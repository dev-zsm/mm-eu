// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lifemeter.h"

void LifeMeter_Init(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;

    interfaceCtx->healthTimer = 320;

    interfaceCtx->health = gSaveContext.save.saveInfo.playerData.health;

    interfaceCtx->lifeColorChange = 0;
    interfaceCtx->lifeColorChangeDirection = 0;

    interfaceCtx->lifeSizeChange = interfaceCtx->lifeColorChange;
    interfaceCtx->lifeSizeChangeDirection = interfaceCtx->lifeColorChangeDirection;

    interfaceCtx->heartsPrimR[0] = 255;
    interfaceCtx->heartsPrimG[0] = 70;
    interfaceCtx->heartsPrimB[0] = 50;

    interfaceCtx->heartsEnvR[0] = 50;
    interfaceCtx->heartsEnvG[0] = 40;
    interfaceCtx->heartsEnvB[0] = 60;

    interfaceCtx->heartsPrimR[1] = 255;
    interfaceCtx->heartsPrimG[1] = 70;
    interfaceCtx->heartsPrimB[1] = 50;

    interfaceCtx->heartsEnvR[1] = 50;
    interfaceCtx->heartsEnvG[1] = 40;
    interfaceCtx->heartsEnvB[1] = 60;

    sHeartsDDPrim[0][0] = sHeartsDDPrim[1][0] = 255;
    sHeartsDDPrim[0][1] = sHeartsDDPrim[1][1] = 255;
    sHeartsDDPrim[0][2] = sHeartsDDPrim[1][2] = 255;

    sHeartsDDEnv[0][0] = sHeartsDDEnv[1][0] = 200;
    sHeartsDDEnv[0][1] = sHeartsDDEnv[1][1] = 0;
    sHeartsDDEnv[0][2] = sHeartsDDEnv[1][2] = 0;
}

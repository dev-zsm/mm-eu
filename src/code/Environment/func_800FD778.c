// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_SetupSkyboxStars(PlayState* play) {
    f32 phi_f0;

    if ((play->envCtx.skybox1Index == 0) && (play->skyboxId == SKYBOX_NORMAL_SKY)) {
        if ((CURRENT_TIME >= CLOCK_TIME(21, 0)) || (CURRENT_TIME < CLOCK_TIME(2, 0))) {
            phi_f0 = 1.0f;
        } else if (CURRENT_TIME > CLOCK_TIME(19, 0)) {
            phi_f0 = 1.0f - ((CLOCK_TIME(21, 0) - CURRENT_TIME) * (1.0f / (CLOCK_TIME(2, 0) + 1)));
        } else if (CURRENT_TIME < CLOCK_TIME(3, 0)) {
            phi_f0 = (CLOCK_TIME(3, 0) - CURRENT_TIME) * (1.0f / (CLOCK_TIME(1, 0) + 1));
        } else {
            phi_f0 = 0.0f;
        }

        phi_f0 = (play->envCtx.skyboxConfig == SKYBOX_CONFIG_24) ? 1.0f : phi_f0;

        ref_D_801F4F28 = phi_f0;
        sEnvSkyboxNumStars = gSkyboxNumStars;
    } else {
        ref_D_801F4F28 = 0.0f;
        sEnvSkyboxNumStars = 0;
    }

    if ((sEnvSkyboxNumStars != 0) && (ref_D_801F4F28 != 0.0f)) {
        OPEN_DISPS(play->state.gfxCtx);

        sSkyboxStarsDList = POLY_OPA_DISP;

        gSPNoOp(POLY_OPA_DISP++);

        CLOSE_DISPS(play->state.gfxCtx);
    } else {
        sSkyboxStarsDList = NULL;
    }
}

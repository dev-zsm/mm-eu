// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void DoorWarp1_Destroy(Actor* thisx, PlayState* play) {
    s32 pad;
    DoorWarp1* this = (DoorWarp1*)thisx;
    s16 i;

    LightContext_RemoveLight(play, &play->lightCtx, this->unk_1DC);
    LightContext_RemoveLight(play, &play->lightCtx, this->unk_1F0);

    for (i = 0; i < ARRAY_COUNT(play->envCtx.adjLightSettings.light1Color); i++) {
        play->envCtx.adjLightSettings.ambientColor[i] = play->envCtx.adjLightSettings.fogColor[i] =
            play->envCtx.adjLightSettings.light1Color[i] = 0;
    }

    if (this->unk_1D3 != 0) {
        DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
    }
}

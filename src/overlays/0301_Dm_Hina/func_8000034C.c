// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_hina.h"

void ref_func_80A1F75C(DmHina* this, PlayState* play) {
    s32 i;

    switch (this->unk17E) {
        case 0:
            this->unk17F = 0;
            this->unk14C = 0.0f;
            break;

        case 1:
            Math_SmoothStepToF(&this->unk14C, 1.0f, 0.4f, 0.05f, 0.001f);
            this->unk17F = this->unk14C * 255.0f;
            this->unk150 = Math_SinS(play->state.frames * 0x1F40);
            for (i = 0; i < ARRAY_COUNT(play->envCtx.adjLightSettings.light1Color); i++) {
                play->envCtx.adjLightSettings.ambientColor[i] = play->envCtx.adjLightSettings.fogColor[i] =
                    play->envCtx.adjLightSettings.light1Color[i] = -255.0f * this->unk14C;
            }

            play->envCtx.adjLightSettings.fogNear = -500.0f * this->unk14C;
            if (play->envCtx.adjLightSettings.fogNear < -300) {
                play->roomCtx.curRoom.segment = NULL;
            }
            break;

        default:
            break;
    }
}

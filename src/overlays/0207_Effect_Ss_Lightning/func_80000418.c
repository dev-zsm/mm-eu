// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_lightning.h"

void EffectSsLightning_Update(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    Vec3f pos;
    s32 yaw;
    f32 scale;
    s32 sign;

    if ((this->rNumBolts != 0) && ((this->life + 1) == this->rLifespan)) {
        sign = (Rand_ZeroOne() < 0.5f) ? -1 : 1;
        yaw = this->rYaw + sign * ((s32)((Rand_ZeroOne() * 3640.0f)) + 0xE38);
        scale = (this->rScale * 0.01f) * 80.0f;

        pos.y = this->pos.y + (Math_SinS(this->rYaw - 0x4000) * scale);

        scale = Math_CosS(this->rYaw - 0x4000) * scale;
        pos.x = this->pos.x - (Math_CosS(Camera_GetInputDirYaw(GET_ACTIVE_CAM(play))) * scale);
        pos.z = this->pos.z + (Math_SinS(Camera_GetInputDirYaw(GET_ACTIVE_CAM(play))) * scale);

        EffectSsLightning_NewLightning(play, &pos, yaw, this);

        if (Rand_ZeroOne() < 0.1f) {
            EffectSsLightning_NewLightning(play, &pos, (this->rYaw * 2) - yaw, this);
        }
    }
}

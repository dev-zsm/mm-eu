// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_sound.h"

void ObjSound_Update(Actor* thisx, PlayState* play) {
    ObjSound* this = (ObjSound*)thisx;

    if (this->soundType == OBJ_SOUND_TYPE_SFX) {
        if (this->sfxType != 0) {
            Actor_PlaySfx_Flagged(&this->actor, gAudioEnvironmentalSfx[this->actor.params]);
        } else {
            Actor_PlaySfx_FlaggedCentered2(&this->actor, gAudioEnvironmentalSfx[this->actor.params]);
        }
    } else if (this->unk_144) {
        if (this->soundType == OBJ_SOUND_TYPE_BGM) {
            Audio_PlayObjSoundBgm(&this->actor.projectedPos, this->actor.params);
        } else if (this->soundType == OBJ_SOUND_TYPE_FIXED_SFX) {
            Audio_PlaySfx_AtFixedPos(&this->actor.projectedPos, gAudioEnvironmentalSfx[this->actor.params]);
        }
    } else {
        this->unk_144 = true;
    }
}

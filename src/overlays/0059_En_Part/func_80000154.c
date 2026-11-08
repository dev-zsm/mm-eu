// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_part.h"

void ref_func_808654C4(EnPart* this, PlayState* play) {
    s16 effectScale;
    Vec3f effectPos;
    Vec3f effectVelocity = { 0.0f, 0.0f, 0.0f };
    s32 i;
    Vec3f pos;

    if (this->actor.params == ENPART_TYPE_15) {
        this->unk146--;
        if (this->unk146 > 0) {
            this->actor.shape.rot.x += 0x3A98;
            this->actor.shape.rot.y = this->actor.shape.rot.y; 
            this->actor.shape.rot.z = this->actor.shape.rot.z; 
            if (BgCheck_SphVsFirstPoly(&play->colCtx, &this->actor.world.pos, 20.0f)) {
                this->unk146 = 0;
            }
        } else {
            Math_Vec3f_Copy(&pos, &this->actor.world.pos);
            pos.y = this->actor.floorHeight;
            ref_func_800B3030(play, &pos, &gZeroVec3f, &gZeroVec3f, this->actor.scale.y * 1400.0f, 7, 0);
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 10, NA_SE_EN_EXTINCT);
            Actor_Kill(&this->actor);
        }
    } else if (this->unk146 <= 0) {
        switch (this->actor.params) {
            case ENPART_TYPE_1:
                ref_func_800B3030(play, &this->actor.world.pos, &gZeroVec3f, &gZeroVec3f, this->actor.scale.y * 4000.0f, 7,
                              1);
                SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 10, NA_SE_EN_EXTINCT);
                break;

            case ENPART_TYPE_4:
                for (i = 7; i >= 0; i--) {
                    effectPos.x = Rand_CenteredFloat(60.0f) + this->actor.world.pos.x;
                    effectPos.y = Rand_CenteredFloat(50.0f) +
                                  (this->actor.world.pos.y + (this->actor.shape.yOffset * this->actor.scale.y));
                    effectPos.z = Rand_CenteredFloat(60.0f) + this->actor.world.pos.z;
                    effectVelocity.y = Rand_ZeroOne() + 1.0f;
                    effectScale = Rand_S16Offset(80, 100);
                    EffectSsDtBubble_SpawnColorProfile(play, &effectPos, &effectVelocity, &gZeroVec3f, effectScale, 25,
                                                       DTBUBBLE_COLOR_PROFILE_RED, true);
                }
                break;

            default:
                break;
        }
        Actor_Kill(&this->actor);
    } else {
        this->unk146--;
        this->zRot += this->unk14C;
    }
}

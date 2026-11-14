// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kakasi.h"

void func_8000002C(Actor* thisx, PlayState* play) {
    EnKakasi* this = (EnKakasi*)thisx;
    s32 csId;
    s32 i;

    Collider_InitAndSetCylinder(play, &this->collider, &this->picto.actor, &ref_D_80971D80);
    SkelAnime_InitFlex(play, &this->skelAnime, &object_ka_Skel_0065B0, &object_ka_Anim_000214, NULL, NULL, 0);

    this->songSummonDist = KAKASI_GET_SUMMON_DISTANCE(&this->picto.actor) * 20.0f;
    if (this->songSummonDist < 40.0f) {
        this->songSummonDist = 40.0f;
    }

    this->unkHeight = (this->picto.actor.world.rot.z * 20.0f) + 60.0f;
    this->picto.actor.world.rot.z = 0;
    this->picto.actor.attentionRangeType = ATTENTION_RANGE_0;
    if ((this->picto.actor.world.rot.x > 0) && (this->picto.actor.world.rot.x < 8)) {
        this->picto.actor.attentionRangeType = KAKASI_GET_ATTENTION_RANGE_TYPE(thisx);
    }
    this->picto.actor.shape.rot.y = this->picto.actor.world.rot.y;

    this->aboveGroundStatus = KAKASI_GET_ABOVE_GROUND(&this->picto.actor);
    this->picto.actor.world.rot.x = 0;
    this->picto.actor.flags |= ACTOR_FLAG_HOOKSHOT_PULLS_PLAYER;
    this->picto.actor.colChkInfo.mass = MASS_IMMOVABLE;
    Actor_SetScale(&this->picto.actor, 0.01f);

    i = 0;
    csId = this->picto.actor.csId;
    while (csId != CS_ID_NONE) {
        
        this->csIdList[i] = csId; \
        csId = CutsceneManager_GetAdditionalCsId(csId);
        
        i++;
    }

    if (this->aboveGroundStatus != 0) {
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_79_08)) {
            this->aboveGroundStatus = ENKAKASI_ABOVE_GROUND_TYPE;
            this->songSummonDist = 80.0f;
            EnKakasi_SetupIdleUnderground(this);
        } else {
            Actor_SetFocus(&this->picto.actor, 60.0f);
            this->picto.validationFunc = EnKakasi_ValidatePictograph;
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_83_01)) {
                EnKakasi_InitTimeSkipDialogue(this);
            } else {
                EnKakasi_SetupIdleStanding(this);
            }
        }
    } else {
        EnKakasi_SetupIdleUnderground(this);
    }
}

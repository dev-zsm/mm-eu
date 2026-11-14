// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kakasi.h"

void func_80001EDC(EnKakasi* this, PlayState* play) {
    Vec3f tempunk238;
    Vec3f tempWorldPos;

    if (this->subCamId != SUB_CAM_ID_DONE) {
        this->unk22C.y = this->picto.actor.home.pos.y + 50.0f;
        this->subCamEyeNext.x = ref_D_80972030.x;
        this->subCamEyeNext.y = ref_D_80972030.y;
        this->subCamEyeNext.z = ref_D_80972030.z;

        Math_Vec3f_Copy(&tempunk238, &this->subCamEyeNext);
        OLib_Vec3fAdd(&this->picto.actor.home, &tempunk238, &this->subCamEyeNext, OLIB_ADD_OFFSET);
        this->subCamAtNext.x = ((f32)ref_D_8097203C.x) + this->unk22C.x;
        this->subCamAtNext.y = ((f32)ref_D_8097203C.y) + this->unk22C.y;
        this->subCamAtNext.z = ((f32)ref_D_8097203C.z) + this->unk22C.z;
        Math_Vec3f_Copy(&this->subCamEye, &this->subCamEyeNext);
        Math_Vec3f_Copy(&this->subCamAt, &this->subCamAtNext);
        ref_func_8096FAAC(this, play);
    }

    if (this->unkCounter1A4 < 15) {
        this->unkCounter1A4++;
        return;
    }

    this->picto.actor.shape.rot.y += 0x3000;
    Math_SmoothStepToS(&this->unk190, 500, 5, 50, 0);
    if ((play->gameplayFrames % 4) == 0) {
        Math_Vec3f_Copy(&tempWorldPos, &this->picto.actor.world.pos);
        tempWorldPos.y = this->picto.actor.floorHeight;
        tempWorldPos.x += Rand_CenteredFloat(2.0f);
        tempWorldPos.z += Rand_CenteredFloat(2.0f);

        if (play->sceneId == SCENE_8ITEMSHOP) {
            EffectSsGSplash_Spawn(play, &tempWorldPos, 0, 0, 0, Rand_CenteredFloat(100.0f) + 200.0f);
            SoundSource_PlaySfxAtFixedWorldPos(play, &tempWorldPos, 0x32, NA_SE_EV_BOMB_DROP_WATER);

        } else {
            Actor_SpawnFloorDustRing(play, &this->picto.actor, &this->picto.actor.world.pos,
            this->picto.actor.shape.shadowScale - 20.0f, 5, 4.0f, 200, 10, true);
            Actor_PlaySfx(&this->picto.actor, NA_SE_EN_AKINDONUTS_HIDE);
        }
    }

    Math_ApproachF(&this->picto.actor.shape.yOffset, -6000.0f, 0.5f, 200.0f);
    if (fabsf(this->picto.actor.shape.yOffset + 6000.0f) < 10.0f) {
        SET_WEEKEVENTREG(WEEKEVENTREG_79_08);
        Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_END);
        CutsceneManager_Stop(this->csIdList[0]);
        this->aboveGroundStatus = ENKAKASI_ABOVE_GROUND_TYPE;
        this->songSummonDist = 80.0f;
        EnKakasi_SetupIdleUnderground(this);
    }
}

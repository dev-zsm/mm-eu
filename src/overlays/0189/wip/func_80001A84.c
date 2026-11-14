// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_DancingNightAway), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_kakasi.h"

void func_80001A84(EnKakasi* this, PlayState* play) {
    f32 curFrame = this->skelAnime.curFrame;
    Vec3f localVec3f;
    Player* player;

    EnKakasi_CheckPlayerPosition(this, play);
    Math_SmoothStepToS(&this->picto.actor.shape.rot.y, this->picto.actor.home.rot.y, 1, 0xBB8, 0);
    this->unk22C.y = this->picto.actor.home.pos.y + 50.0f;

    this->subCamEyeNext.x = ref_D_80971E38[this->unk190].x;
    this->subCamEyeNext.y = ref_D_80971E38[this->unk190].y;
    this->subCamEyeNext.z = ref_D_80971E38[this->unk190].z;
    Math_Vec3f_Copy(&localVec3f, &this->subCamEyeNext);
    OLib_Vec3fAdd(&this->picto.actor.home, &localVec3f, &this->subCamEyeNext, OLIB_ADD_OFFSET);

    this->subCamAtNext.x = ref_D_80971EEC[this->unk190].x + this->unk22C.x;
    this->subCamAtNext.y = ref_D_80971EEC[this->unk190].y + this->unk22C.y;
    this->subCamAtNext.z = ref_D_80971EEC[this->unk190].z + this->unk22C.z;
    if ((this->unk190 != 6) && (this->unk190 != 7)) {
        Math_Vec3f_Copy(&this->subCamEye, &this->subCamEyeNext);
        Math_Vec3f_Copy(&this->subCamAt, &this->subCamAtNext);
    }
    if ((this->unk190 >= 7) && (this->unk190 != 0xE)) {
        this->picto.actor.shape.rot.y += 0x800;
    }

    ref_func_8096FAAC(this, play);

    
    switch (this->unk190) {
        case 0:
            
            this->unk204 = 0x28;
            this->unk190++;
            break;

        case 1:
            
            if ((this->unk204 == 0) && (curFrame >= this->animEndFrame)) {
                this->unk204 = 0x14;
                this->unk190++;
                EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
            }
            break;

        case 2:
            
            if (this->unk204 == 0) {
                this->unk204 = 0x14;
                this->unk190++;
            }
            break;

        case 3:
            
            if (this->unk204 == 0) {
                this->unk204 = 0x14;
                this->unk190++;
            }
            break;

        case 4:
            
            if (this->unk204 == 0) {
                this->unk204 = 0x14;
                this->unk190++;
            }
            break;

        case 5:
            
            if (this->unk204 == 0) {
                this->unk204 = 0xF;
                this->unk190++;
            }
            break;

        case 6:
            
            if (this->unk204 == 0) {
                this->unk204 = 0xF;
                this->unk190++;
            }
            break;

        case 7:
            
            if (this->unk204 == 0) {
                this->unk204 = 0xA;
                this->unk190++;
            }
            break;

        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            
            if (this->unk204 == 0) {
                this->unk190++;
                this->unk204 = 0xA;
                if (this->unk190 == 0xE) {
                    Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_73);
                    Play_DisableMotionBlur();
                    this->unk204 = 0x14;
                }
            }
            break;

        case 14:
            
            
            Math_SmoothStepToS(&this->picto.actor.shape.rot.y, this->picto.actor.yawTowardsPlayer, 5, 0x3E8, 0);
            if (this->unk204 == 0) {
                player = GET_PLAYER(play);

                Play_SetRespawnData(play, RESPAWN_MODE_DOWN, Entrance_CreateFromSpawn(0), player->unk_3CE,
                                    PLAYER_PARAMS(0xFF, PLAYER_START_MODE_B), &player->unk_3C0, player->unk_3CC);
                ref_func_80169EFC(play);

                if ((CURRENT_TIME > CLOCK_TIME(18, 0)) || (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                    gSaveContext.save.time = CLOCK_TIME(6, 0);
                    gSaveContext.respawnFlag = -4;
                    SET_EVENTINF(EVENTINF_TRIGGER_DAYTELOP);
                } else {
                    gSaveContext.save.time = CLOCK_TIME(18, 0);
                    gSaveContext.respawnFlag = -8;
                }
                SET_WEEKEVENTREG(WEEKEVENTREG_83_01);
                this->unk190 = 0;
                this->actionFunc = EnKakasi_DoNothing;
            }
            break;

        default:
            break;
    }
}

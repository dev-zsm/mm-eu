// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void EnGoroiwa_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnGoroiwa* this = (EnGoroiwa*)thisx;
    f32 temp_f0;
    s32 pathIndex = ENGOROIWA_GET_PATH_INDEX(&this->actor);
    Path* path = &play->setupPathList[pathIndex];

    Actor_ProcessInitChain(&this->actor, sInitChain);
    this->actor.world.rot.x = 0;
    this->actor.world.rot.z = 0;
    this->actor.world.rot.y = Rand_Next() & 0xFFFF;
    this->actor.shape.rot.y = this->actor.world.rot.y;
    this->actor.shape.rot.x = 0;
    this->actor.shape.rot.z = 0;
    ref_func_8093E8A0(this);
    ref_func_8093E91C(this);
    ref_func_8093E9B0(this, play);

    if (pathIndex == ENGOROIWA_PATH_INDEX_NONE) {
        Actor_Kill(&this->actor);
        return;
    }

    if (path->count < 2) {
        Actor_Kill(&this->actor);
        return;
    }

    if ((this->actor.home.rot.y >= (path->count - 1)) && (this->actor.home.rot.y < 0)) {
        this->actor.home.rot.y = 0;
    }

    CollisionCheck_SetInfo(&this->actor.colChkInfo, NULL, &sColChkInfoInit);
    ActorShape_Init(&this->actor.shape, 595.0f, ActorShadow_DrawCircle, 9.4f);
    this->actor.shape.shadowAlpha = 200;
    ref_func_8093EB58(this, play);

    this->pathPoints = Lib_SegmentedToVirtual(path->points);

    ref_func_8093EE18(this, play);
    ref_func_8093EE64(this, this->actor.home.rot.y);
    ref_func_8093EEBC(this);
    ref_func_8093EC50(this);

    if (ENGOROIWA_GET_3000(&this->actor) == ENGOROIWA_3000_2) {
        temp_f0 = ref_func_8093EB74(this, play);

        if (temp_f0 < 0.1f) {
            this->unk_1E0 = 0.0f;
        } else {
            this->unk_1E0 = (ref_D_80942DFC[this->unk_1E4] * ((s32)play->state.framerateDivisor * 0.5f)) / temp_f0;
            this->unk_1E0 *= 0.020000001f;
            if (this->unk_1E0 > 0.00037f) {
                this->unk_1E0 = 0.00037f;
            } else if (this->unk_1E0 < 0.00015f) {
                this->unk_1E0 = 0.00015f;
            }
        }
    }

    Effect_Add(play, &this->unk_248, EFFECT_TIRE_MARK, 0, 0, &ref_D_80942E8C);
    ref_func_809419D0(this);
}

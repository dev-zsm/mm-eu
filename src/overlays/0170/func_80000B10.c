// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

void BgIngate_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    BgIngate* this = (BgIngate*)thisx;
    s32 phi_a2;
    Vec3s* sp38;
    Vec3f sp2C;
    Vec3f sp20;

    if (BgIngate_FindActor(this, play, ACTORCAT_BG, ACTOR_BG_INGATE) == NULL) {
        DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS | DYNA_TRANSFORM_ROT_Y);
        DynaPolyActor_LoadMesh(play, &this->dyna, &gSichitaiBoatCol);
        this->unk160 = 0;
        this->unk160 |= 0x8;
        this->unk160 |= 0x10;
        Actor_SetScale(&this->dyna.actor, 1.0f);
        this->timePath = SubS_GetAdditionalPath(play, BGINGATE_GET_PATH_INDEX(&this->dyna.actor), 0);
        this->dyna.actor.room = -1;
#if MM_VERSION >= N64_US
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_WOODFALL_TEMPLE)) {
            CLEAR_WEEKEVENTREG(WEEKEVENTREG_90_40);
        }
#endif
        if (!CHECK_EVENTINF(EVENTINF_35) && CHECK_WEEKEVENTREG(WEEKEVENTREG_90_40)) {
            phi_a2 = 1;
            this->unk16C = 1;
            this->actionFunc = ref_func_809541B8;
        } else {
            phi_a2 = 0;
            if (play->curSpawn == 6) {
                ref_func_80953F14(this, play);
                if (CHECK_EVENTINF(EVENTINF_35)) {
                    Interface_InitMinigame(play);
                } else {
                    SET_EVENTINF(EVENTINF_41);
                }
            } else {
                this->actionFunc = ref_func_80953F8C;
            }
        }
        this->timePath = SubS_GetAdditionalPath(play, BGINGATE_GET_PATH_INDEX(&this->dyna.actor), phi_a2);
        if (this->timePath != NULL) {
            sp38 = Lib_SegmentedToVirtual(this->timePath->points);
            Math_Vec3s_ToVec3f(&sp2C, &sp38[0]);
            Math_Vec3s_ToVec3f(&sp20, &sp38[1]);
            this->dyna.actor.world.rot.y = Math_Vec3f_Yaw(&sp2C, &sp20);
            this->dyna.actor.shape.rot.y = this->dyna.actor.world.rot.y;
            this->dyna.actor.world.pos.x = sp2C.x;
            this->dyna.actor.world.pos.y = -15.0f;
            this->dyna.actor.world.pos.z = sp2C.z;
        }
        this->timePath = SubS_GetAdditionalPath(play, BGINGATE_GET_PATH_INDEX(&this->dyna.actor), 0);
    } else {
        Actor_Kill(&this->dyna.actor);
    }
}

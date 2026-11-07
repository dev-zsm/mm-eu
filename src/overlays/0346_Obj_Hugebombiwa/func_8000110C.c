// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A54CEC(ObjHugebombiwa* this, PlayState* play) {
    s32 pad;

    if (CutsceneManager_IsNext(this->actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        Flags_SetSwitch(play, ENHUGEBOMBIWA_GET_SWITCH_FLAG(&this->actor));
        if (!ENHUGEBOMBIWA_GET_100(&this->actor) &&
            ((play->sceneId == SCENE_17SETUGEN) || (play->sceneId == SCENE_17SETUGEN2))) {
            SET_WEEKEVENTREG(WEEKEVENTREG_19_02);
        }

        if (!ENHUGEBOMBIWA_GET_100(&this->actor)) {
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 80, NA_SE_EV_WALL_BROKEN);
        } else {
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 80, NA_SE_EV_SNOWBALL_BROKEN);
        }

        if (!ENHUGEBOMBIWA_GET_100(&this->actor)) {
            ref_func_80A53BE0(play, &this->actor.world.pos);
            ref_func_80A54E10(this);
        } else {
            ref_func_80A541F4(this, play);
            ref_func_80A55310(this);
        }
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}

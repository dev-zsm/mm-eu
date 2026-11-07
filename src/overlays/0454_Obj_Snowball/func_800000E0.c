// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B02DB0(ObjSnowball* this, PlayState* play) {
    s32 pad;
    ObjSnowballStruct2* ptr = &ref_D_80B04F84[this->actor.home.rot.y];

    Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, ptr->unk_00, this->actor.home.pos.x, this->actor.home.pos.y,
                                  this->actor.home.pos.z, this->actor.home.rot.x, 0, this->actor.home.rot.z,
                                  this->actor.params | ptr->unk_02, CutsceneManager_GetAdditionalCsId(this->actor.csId),
                                  this->actor.halfDaysBits, NULL);
}

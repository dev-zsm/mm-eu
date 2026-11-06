// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B80440(BgIkanaRotaryroom* this, PlayState* play) {
    s32 pad;
    Vec3f sp50;

    Matrix_Push();
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
    if (Flags_GetSwitch(play, BGIKANAROTARYROOM_GET_SWITCH_FLAG_2(&this->dyna.actor))) {
        Matrix_Translate(ref_D_80B82178.x, ref_D_80B82178.y, ref_D_80B82178.z, MTXMODE_APPLY);
    } else {
        Matrix_Translate(ref_D_80B8216C.x, ref_D_80B8216C.y, ref_D_80B8216C.z, MTXMODE_APPLY);
    }
    Matrix_MultZero(&sp50);
    ref_func_80B80358(&sp50);
    this->unk_204.unk_00 = Actor_SpawnAsChildAndCutscene(
        &play->actorCtx, play, ACTOR_BG_IKANA_BLOCK, sp50.x, sp50.y, sp50.z, this->dyna.actor.shape.rot.x,
        this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z, -1,
        CutsceneManager_GetAdditionalCsId(this->dyna.actor.csId), this->dyna.actor.halfDaysBits, NULL);
    Matrix_Pop();
}

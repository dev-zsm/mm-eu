// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

s32 ref_func_80B80F08(BgIkanaRotaryroom* this, PlayState* play) {
    s32 pad;
    BgIkanaBlock* ikanaBlock = (BgIkanaBlock*)this->unk_204.unk_00;
    Vec3f sp34;
    Vec3f sp28;
    s32 sp24 = false;

    if (ikanaBlock != NULL) {
        Matrix_Push();

        Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                     this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
        Matrix_Translate(ref_D_80B82178.x, ref_D_80B82178.y, ref_D_80B82178.z, MTXMODE_APPLY);
        Matrix_MultZero(&sp34);
        Matrix_SetTranslateRotateYXZ(ikanaBlock->dyna.actor.world.pos.x,
                                     ikanaBlock->dyna.actor.world.pos.y + ikanaBlock->unk_170,
                                     ikanaBlock->dyna.actor.world.pos.z, &ikanaBlock->dyna.actor.shape.rot);
        Matrix_MultZero(&sp28);

        Matrix_Pop();

        if (Math3D_Vec3fDistSq(&sp34, &sp28) < 3.0f) {
            if (!Flags_GetSwitch(play, BGIKANAROTARYROOM_GET_SWITCH_FLAG_2(&this->dyna.actor))) {
                sp24 = true;
            }
            Flags_SetSwitch(play, BGIKANAROTARYROOM_GET_SWITCH_FLAG_2(&this->dyna.actor));
        }
    }
    return sp24;
}

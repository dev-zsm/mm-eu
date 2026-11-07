// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void BgIkanaRotaryroom_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIkanaRotaryroom* this = (BgIkanaRotaryroom*)thisx;
    s32 sp34 = BGIKANAROTARYROOM_GET_1(&this->dyna.actor);

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    if (Flags_GetSwitch(play, BGIKANAROTARYROOM_GET_SWITCH_FLAG_1(&this->dyna.actor))) {
        this->dyna.actor.shape.rot.x = -0x8000;
    } else {
        this->dyna.actor.shape.rot.x = 0;
    }

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, ref_D_80B82218[sp34]);

    Collider_InitJntSph(play, &this->collider);
    if (!sp34) {
        Collider_SetJntSph(play, &this->collider, &this->dyna.actor, &sJntSphInit1, this->colliderElements);
    } else {
        Collider_SetJntSph(play, &this->collider, &this->dyna.actor, &sJntSphInit2, this->colliderElements);
    }

    ref_func_80B802E0(this);

    if (sp34 == true) {
        this->unk_1FC = Lib_SegmentedToVirtual(&object_ikana_obj_Matanimheader_007B68);
    }

    if (!sp34) {
        ref_func_80B80440(this, play);
    } else {
        ref_func_80B81570(this, play);
    }

    ref_func_80B80550(this, play);
    ref_func_80B818B4(this);
}

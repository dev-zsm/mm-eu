// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ObjHunsui_Init(Actor* thisx, PlayState* play) {
    ObjHunsui* this = (ObjHunsui*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->unk_160 = OBJHUNSUI_GET_F000(thisx);
    this->unk_164 = OBJHUNSUI_GET_F80(thisx);
    this->switchFlag = OBJHUNSUI_GET_SWITCH_FLAG(thisx);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);

    if ((this->unk_160 != OBJHUNSUI_F000_5) && (this->unk_160 != OBJHUNSUI_F000_6)) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &object_hunsui_Colheader_000C74);
    }

    ref_D_80B9DED0 = Lib_SegmentedToVirtual(object_hunsui_Matanimheader_000BF0);
    ref_D_80B9DED4 = Lib_SegmentedToVirtual(object_hunsui_Matanimheader_001888);
    SubS_FillCutscenesList(&this->dyna.actor, this->csIdList, ARRAY_COUNT(this->csIdList));
    this->unk_18C = 0;

    switch (this->unk_160) {
        case OBJHUNSUI_F000_1:
        case OBJHUNSUI_F000_2:
        case OBJHUNSUI_F000_3:
        case OBJHUNSUI_F000_4:
        case OBJHUNSUI_F000_5:
        case OBJHUNSUI_F000_6:
            this->dyna.actor.cullingVolumeScale = 900.0f;
            this->dyna.actor.cullingVolumeDownward = 90.0f;
            this->dyna.actor.cullingVolumeDistance = 4000.0f;
            break;
    }

    switch (this->unk_160) {
        case OBJHUNSUI_F000_5:
            if (ref_D_80B9DED8.unk_01 == 0) {
                ref_D_80B9DED8.unk_01 = 1;
                this->unk_16C = this->dyna.actor.room;
                this->unk_16D = this->dyna.actor.world.rot.z;
                this->dyna.actor.world.rot.z = 0;
                this->dyna.actor.shape.rot.z = 0;
                this->dyna.actor.room = -1;
            } else {
                Actor_Kill(&this->dyna.actor);
                return;
            }
            break;

        case OBJHUNSUI_F000_6:
            if (ref_D_80B9DED8.unk_02 == 0) {
                ref_D_80B9DED8.unk_02 = 1;
                this->unk_16C = this->dyna.actor.room;
                this->unk_16D = this->dyna.actor.world.rot.z;
                this->dyna.actor.world.rot.z = 0;
                this->dyna.actor.shape.rot.z = 0;
                this->dyna.actor.room = -1;
            } else {
                Actor_Kill(&this->dyna.actor);
                return;
            }
            break;
    }

    switch (this->unk_160) {
        case OBJHUNSUI_F000_0:
            if (ref_D_80B9DED8.unk_00 == 0) {
                ref_D_80B9DED8.unk_00 = 1;
                this->unk_16C = this->dyna.actor.room;
                this->unk_16D = this->unk_164;
                
                this->dyna.actor.room = -1; this->actionFunc = ref_func_80B9D714;
                
            } else {
                Actor_Kill(&this->dyna.actor);
                return;
            }
            break;

        case OBJHUNSUI_F000_2:
            this->unk_172 |= 1;
            FALLTHROUGH;
        case OBJHUNSUI_F000_1:
            this->dyna.actor.draw = ref_func_80B9DA60;
            if ((this->unk_172 & 1) && ref_func_80B9C450(play, this->switchFlag, this->unk_164)) {
                this->unk_174 = 240.0f;
                this->unk_172 |= 4;
                this->unk_184 = 0xFF0;
            } else {
                this->unk_174 = -30.0f;
                this->unk_172 |= 2;
                this->unk_184 = 0;
            }
            this->unk_178 = this->unk_174;
            this->unk_180 = ref_func_80B9C450(play, this->switchFlag, this->unk_164);
            this->actionFunc = ref_func_80B9CE64;
            break;

        case OBJHUNSUI_F000_4:
            this->unk_172 |= 1;
            FALLTHROUGH;
        case OBJHUNSUI_F000_3:
        case OBJHUNSUI_F000_5:
        case OBJHUNSUI_F000_6:
            this->dyna.actor.draw = ref_func_80B9DA60;
            if ((this->unk_160 == OBJHUNSUI_F000_5) || (this->unk_160 == OBJHUNSUI_F000_6)) {
                ref_func_80B9D2BC(this, play);
                this->unk_178 = this->unk_174;
            } else {
                if ((this->unk_172 & 1) || ref_func_80B9C450(play, this->switchFlag, this->unk_164)) {
                    ref_func_80B9D4D0(this, play);
                } else {
                    ref_func_80B9D0FC(this, play);
                }
                this->unk_178 = this->unk_174;
            }
            break;
    }
}

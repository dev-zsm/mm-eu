// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

void ObjOshihiki_Init(Actor* thisx, PlayState* play) {
    ObjOshihiki* this = (ObjOshihiki*)thisx;

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);

    if ((OBJOSHIHIKI_GET_FF00(&this->dyna.actor) >= OBJOSHIHIKI_FF00_0) &&
        (OBJOSHIHIKI_GET_FF00(&this->dyna.actor) < OBJOSHIHIKI_FF00_80)) {
        if (Flags_GetSwitch(play, OBJOSHIHIKI_GET_SWITCH_FLAG(&this->dyna.actor))) {
            switch (OBJOSHIHIKI_GET_F(&this->dyna.actor)) {
                case OBJOSHIHIKI_F_0:
                case OBJOSHIHIKI_F_1:
                case OBJOSHIHIKI_F_2:
                    Actor_Kill(&this->dyna.actor);
                    return;

                default:
                    break;
            }
        } else {
            switch (OBJOSHIHIKI_GET_F(&this->dyna.actor)) {
                case OBJOSHIHIKI_F_3:
                case OBJOSHIHIKI_F_4:
                case OBJOSHIHIKI_F_5:
                    Actor_Kill(&this->dyna.actor);
                    return;

                default:
                    break;
            }
        }
    }

    DynaPolyActor_LoadMesh(play, &this->dyna, &gameplay_dangeon_keep_Colheader_007498);
    this->texture = Lib_SegmentedToVirtual(gameplay_dangeon_keep_Matanimheader_01B370);
    ObjOshihiki_SetScale(this, play);
    ObjOshihiki_SetTextureStep(this, play);
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
    ObjOshihiki_SetColor(this, play);
    ObjOshihiki_ResetFloors(this);
    ObjOshihiki_SetupOnActor(this, play);
}

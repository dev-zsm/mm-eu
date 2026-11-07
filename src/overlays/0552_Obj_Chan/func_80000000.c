// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjChan* this = (ObjChan*)thisx;

    if (OBJCHAN_SUBTYPE(&this->actor) == OBJCHAN_SUBTYPE_CHANDELIER) {
        if (sObjChanLoaded) {
            Actor_Kill(&this->actor);
            return;
        }
        this->actor.room = -1;
        sObjChanLoaded = true;
    }
    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sObjChanCylinderInit);
    SubS_FillCutscenesList(&this->actor, this->csIdList, ARRAY_COUNT(this->csIdList));
    switch (OBJCHAN_SUBTYPE(&this->actor)) {
        case OBJCHAN_SUBTYPE_CHANDELIER:
            this->rotation = this->actor.shape.rot.y;
            this->actor.shape.rot.y = 0;
            ObjChan_InitChandelier(this, play);
            break;

        case OBJCHAN_SUBTYPE_POT:
            this->actor.draw = ObjChan_DrawPot;
            ObjChan_InitPot(this, play);
            break;

        default:
            break;
    }
}

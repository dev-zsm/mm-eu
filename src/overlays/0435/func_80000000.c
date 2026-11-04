// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ObjBigicicle_Init(Actor* thisx, PlayState* play) {
    ObjBigicicle* this = (ObjBigicicle*)thisx;
    f32 sp30;
    s32 sp28;

    Actor_ProcessInitChain(&this->actor, sInitChain);

    sp28 = OBJBIGICLE_GET_FF00(&this->actor);
    if ((sp28 == 0) || (sp28 == 0xFF)) {
        sp28 = 0x3C;
    }
    Actor_SetScale(&this->actor, sp28 * 0.001f);

    this->actor.params = OBJBIGICLE_GET_SWITCH_FLAG_MASK(&this->actor);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    sp30 = sp28 * (1.0f / 60.0f);

    Collider_InitAndSetCylinder(play, &this->collider1, &this->actor, &sCylinderInit1);
    this->collider1.dim.radius *= sp30;
    this->collider1.dim.height *= sp30;
    this->collider1.dim.yShift *= sp30;

    Collider_InitAndSetCylinder(play, &this->collider2, &this->actor, &sCylinderInit2);
    this->collider2.dim.radius *= sp30;
    this->collider2.dim.height *= sp30;
    this->collider2.dim.yShift *= sp30;

    if (Flags_GetSwitch(play, OBJBIGICLE_GET_SWITCH_FLAG(&this->actor))) {
        Actor_Kill(&this->actor);
        return;
    }

    this->unk_148 = this->actor.shape.rot.x;
    this->actor.shape.rot.x = 0x4000;

    Collider_UpdateCylinder(&this->actor, &this->collider1);
    Collider_UpdateCylinder(&this->actor, &this->collider2);

    if (!ref_D_80AE9890) {
        ref_D_80AE9878 = Lib_SegmentedToVirtual(ref_D_80AE9878);
        ref_D_80AE9890 = true;
    }

    this->unk_149 = 0;
    this->actionFunc = ref_func_80AE8FD4;
}

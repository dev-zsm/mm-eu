// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ice_poly.h"

void ObjIcePoly_Init(Actor* thisx, PlayState* play) {
    ObjIcePoly* this = (ObjIcePoly*)thisx;
    s32 i;

    this->switchFlag = OBJICEPOLY_GET_SWITCH_FLAG(thisx);
    thisx->params = OBJICEPOLY_GET_SCALE(thisx);
    thisx->cullingVolumeDistance = 5600.0f;

    Actor_SetScale(thisx, thisx->params * 0.01f);

    for (i = 0; i < ARRAY_COUNT(this->colliders1); i++) {
        Collider_InitAndSetCylinder(play, &this->colliders1[i], thisx, &sCylinderInit1);
        Collider_InitAndSetCylinder(play, &this->colliders2[i], thisx, &sCylinderInit2);
        Collider_UpdateCylinder(thisx, &this->colliders1[i]);
        Collider_UpdateCylinder(thisx, &this->colliders2[i]);
    }

    this->colliders1[0].dim.radius = thisx->scale.x * 48.0f;
    this->colliders1[0].dim.height = thisx->scale.y * 58.0f;
    this->colliders2[0].dim.height = this->colliders1[0].dim.height;
    this->colliders2[0].dim.radius = this->colliders1[0].dim.radius + 17;

    this->colliders1[1].dim.radius = thisx->scale.x * 23.0f;
    this->colliders1[1].dim.height = thisx->scale.y * 50.0f;
    this->colliders2[1].dim.radius = this->colliders1[1].dim.radius;
    this->colliders2[1].dim.height = this->colliders1[1].dim.height;

    this->colliders1[1].dim.yShift = this->colliders1[0].dim.height;
    this->colliders2[1].dim.yShift = this->colliders1[1].dim.yShift;

    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    this->unk_148 = 255;

    Actor_SetFocus(thisx, thisx->scale.y * 30.0f);

    thisx->shape.rot.x = 0x500;
    thisx->shape.rot.z = -0x500;

    if (((this->switchFlag != OBJICEPOLY_SWITCH_FLAG_NONE) && Flags_GetSwitch(play, this->switchFlag)) ||
        ((play->sceneId == SCENE_KAJIYA) && CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_SNOWHEAD_TEMPLE))) {
        Actor_Kill(thisx);
        return;
    }

    this->actionFunc = ref_func_80931A38;
}

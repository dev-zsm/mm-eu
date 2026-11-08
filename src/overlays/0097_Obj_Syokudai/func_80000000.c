// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_syokudai.h"

void ObjSyokudai_Init(Actor* thisx, PlayState* play) {
    ObjSyokudai* this = (ObjSyokudai*)thisx;
    s32 pad;
    s32 type = OBJ_SYOKUDAI_GET_TYPE(thisx);
    s32 switchFlag = OBJ_SYOKUDAI_GET_SWITCH_FLAG(thisx);

    Actor_ProcessInitChain(thisx, sInitChain);
    ref_func_800B4AEC(play, thisx, 50.0f);
    ActorShape_Init(&thisx->shape, 0.0f, ref_func_800B4B50, 1.0f);
    Collider_InitAndSetCylinder(play, &this->standCollider, thisx, &sStandColliderInit);
    this->standCollider.base.colMaterial = sColMaterials[OBJ_SYOKUDAI_GET_TYPE(thisx)];
    Collider_InitAndSetCylinder(play, &this->flameCollider, thisx, &sFlameColliderInit);
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    Lights_PointGlowSetInfo(&this->lightInfo, thisx->world.pos.x, thisx->world.pos.y + OBJ_SYOKUDAI_GLOW_HEIGHT,
                            thisx->world.pos.z, 0xFF, 0xFF, 0xB4, -1);
    this->lightNode = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo);

    if (OBJ_SYOKUDAI_GET_START_LIT(thisx) ||
        (((type != OBJ_SYOKUDAI_TYPE_NO_SWITCH) || (switchFlag != OBJ_SYOKUDAI_SWITCH_FLAG_NONE)) &&
         Flags_GetSwitch(play, switchFlag))) {
        s32 groupSize = OBJ_SYOKUDAI_GET_GROUP_SIZE(thisx);

        this->snuffTimer = OBJ_SYOKUDAI_SNUFF_NEVER;
        if (groupSize != 0) {
            sNumLitTorchesInGroup = groupSize;
        }
    } else {
        sNumLitTorchesInGroup = 0;
    }
    this->flameTexScroll = (u32)(Rand_ZeroOne() * OBJ_SYOKUDAI_SNUFF_DEFAULT);
    Actor_SetFocus(thisx, 60.0f);
}

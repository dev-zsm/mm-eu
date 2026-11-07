// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void BgHakuginSwitch_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgHakuginSwitch* this = (BgHakuginSwitch*)thisx;
    s32 sp34 = BGHAKUGINSWITCH_GET_7(&this->dyna.actor);
    s32 sp30;
    s32 pad2;
    s32 sp28;

    if (Flags_GetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
        sp30 = true;
    } else {
        sp30 = false;
    }

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_goronswitch_Colheader_0005C8);

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);

    this->unk_1B2 = 15;
    if (!BGHAKUGINSWITCH_GET_10(&this->dyna.actor)) {
        Actor_ProcessInitChain(&this->dyna.actor, sInitChain1);

        this->dyna.actor.scale.x = 0.07f;
        this->dyna.actor.scale.y = 0.016f;
        this->dyna.actor.scale.z = 0.07f;
        this->collider.dim.radius = 46;
        this->collider.dim.yShift = 0x1D;

        this->unk_1A8 = object_goronswitch_DL_000268;
        this->csId = this->dyna.actor.csId;

        if (sp34 == 0) {
            this->additionalCsId = CS_ID_NONE;
        } else {
            this->additionalCsId = CutsceneManager_GetAdditionalCsId(this->csId);
        }

        if (sp30) {
            ref_func_80B16494(this, play);
        } else {
            ref_func_80B16244(this, play);
        }
    } else {
        if (ref_D_80B1688C[sp34].unk_14 & 4) {
            sp28 = true;
        } else {
            sp28 = false;
        }

        Actor_ProcessInitChain(&this->dyna.actor, sInitChain2);

        this->unk_1A8 = ref_D_80B1688C[sp34].unk_10;
        this->csId = this->dyna.actor.csId;
        this->additionalCsId = CutsceneManager_GetAdditionalCsId(this->csId);

        if (sp30 == sp28) {
            ref_func_80B15F3C(this, play);
        } else {
            ref_func_80B15B1C(this, play);
        }
    }

    this->unk_1C8 = 1.0f / this->dyna.actor.scale.y;
}

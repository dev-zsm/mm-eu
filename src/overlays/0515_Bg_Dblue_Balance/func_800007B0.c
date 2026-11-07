// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void BgDblueBalance_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgDblueBalance* this = (BgDblueBalance*)thisx;
    s32 sp2C = BGDBLUEBALANCE_GET_300(&this->dyna.actor);
    s32 pad2;
    s32 isSwitchFlagSet = Flags_GetSwitch(play, BGDBLUEBALANCE_GET_SWITCH_FLAG(&this->dyna.actor));

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    this->dyna.actor.flags = sTypeInfo[sp2C].unk_08;
    this->dyna.actor.cullingVolumeScale = sTypeInfo[sp2C].unk_0C;
    this->dyna.actor.cullingVolumeDownward = sTypeInfo[sp2C].unk_10;
    this->dyna.actor.update = sTypeInfo[sp2C].update;
    this->dyna.actor.draw = sTypeInfo[sp2C].draw;

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, sTypeInfo[sp2C].colHeader);

    if (sp2C == 3) {
        ref_D_80B83C70 = Lib_SegmentedToVirtual(gGreatBayTempleObjectWaterwheelSplashTexAnim);
    } else if (sp2C == 0) {
        ref_D_80B83C74 = Lib_SegmentedToVirtual(gGreatBayTempleObjectSeesawSplashTexAnim);
    }

    if (sp2C == 0) {
        if (isSwitchFlagSet) {
            this->dyna.actor.shape.rot.z = -0x1C72;
            this->unk_174 = -0x1C72;
        } else {
            this->dyna.actor.shape.rot.z = 0x1C72;
            this->unk_174 = 0x1C72;
        }
        ref_func_80B82454(this, play);
        ref_func_80B8259C(this, play);
        ref_func_80B82DC4(this);
    } else if (sp2C == 3) {
        this->isSwitchFlagSet2 = isSwitchFlagSet;
        this->isSwitchFlagSet = isSwitchFlagSet;
        if (isSwitchFlagSet) {
            ref_func_80B83344(this);
        } else {
            this->unk_178 = 0x1F4;
            ref_func_80B833A8(this);
        }
    }
}

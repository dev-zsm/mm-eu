// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

u32 EffectSsKakera_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsKakeraInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->life = initParams->life;
    this->priority = 101;
    if (initParams->dList != NULL) {
        this->gfx = initParams->dList;
        switch (initParams->objectId) {
            case GAMEPLAY_KEEP:
            case GAMEPLAY_FIELD_KEEP:
            case GAMEPLAY_DANGEON_KEEP:
                this->rObjectId = KAKERA_OBJECT_DEFAULT;
                break;

            default:
                this->rObjectId = initParams->objectId;
                EffectSsKakera_CheckForObject(this, play);
                break;
        }
    } else {
        _dbg_hungup("../z_eff_kakera.c", 193);
    }
    this->draw = EffectSsKakera_Draw;
    this->update = EffectSsKakera_Update;
    this->vec = initParams->unk_18;
    this->rReg0 = initParams->unk_2C;
    this->rGravity = initParams->gravity;
    this->rPitch = Rand_ZeroOne() * 0x8000;
    this->rYaw = Rand_ZeroOne() * 0x8000;
    this->rReg4 = initParams->unk_26;
    this->rReg5 = initParams->unk_28;
    this->rReg6 = initParams->unk_2A;
    this->rScale = initParams->scale;
    this->rReg8 = initParams->unk_30;
    this->rReg9 = initParams->unk_32;
    this->rColorIndex = initParams->colorIdx;
    return 1;
}

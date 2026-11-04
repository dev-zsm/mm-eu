// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_boom.h"

void EnBoom_Init(Actor* thisx, PlayState* play) {
    static u8 ref_D_808A3068[4] = { 255, 255, 100, 255 };
    static u8 ref_D_808A306C[4] = { 255, 255, 100, 64 };
    static u8 ref_D_808A3070[4] = { 255, 255, 100, 0 };
    static u8 ref_D_808A3074[4] = { 255, 255, 100, 0 };
    s32 pad;
    EnBoom* this = (EnBoom*)thisx;
    EffectBlureInit1 sp30;
    s32 i;

    this->actor.room = -1;
    Actor_ProcessInitChain(&this->actor, sInitChain);

    for (i = 0; i < 4; i++) {
        sp30.p1StartColor[i] = ref_D_808A3068[i];
        sp30.p2StartColor[i] = ref_D_808A306C[i];
        sp30.p1EndColor[i] = ref_D_808A3070[i];
        sp30.p2EndColor[i] = ref_D_808A3074[i];
    }

    sp30.elemDuration = 8;
    sp30.unkFlag = 0;
    sp30.calcMode = 0;

    Effect_Add(play, &this->effectIndex, EFFECT_BLURE1, 0, 0, &sp30);

    Collider_InitQuad(play, &this->collider);
    Collider_SetQuad(play, &this->collider, &this->actor, &sQuadInit);
    EnBoom_SetupAction(this, ref_func_808A2918);
}

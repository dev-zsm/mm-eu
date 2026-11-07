// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA11C(EnRr* this) {
    this->drawDmgEffType = ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX;
    this->collider1.base.colMaterial = COL_MATERIAL_HIT3;
    this->collider1.elem.elemMaterial = ELEM_MATERIAL_UNK0;
    this->unk_1EE = 80;
    this->drawDmgEffScale = 0.85f;
    this->drawDmgEffFrozenSteamScale = 1275.0f * 0.001f;
    this->drawDmgEffAlpha = 1.0f;
    this->actor.flags &= ~ACTOR_FLAG_HOOKSHOT_PULLS_PLAYER;
    Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_RED, 255, COLORFILTER_BUFFLAG_OPA, 80);
}

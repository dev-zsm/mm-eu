// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_aqua.h"

void ObjAqua_Init(Actor* thisx, PlayState* play) {
    ObjAqua* this = (ObjAqua*)thisx;
    s32 i;

    Actor_ProcessInitChain(thisx, sInitChain);
    this->actor.scale.x = 0.0009f;
    this->actor.scale.y = 0.0005f;
    this->actor.scale.z = 0.0009f;
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, thisx, &sCylinderInit);
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 60.0f);

    thisx->shape.shadowAlpha = 140;
    this->alpha = 255;
    if (ObjAqua_IsUnderwater(this, play)) {
        for (i = 0; i < 8; i++) {
            EffectSsBubble_Spawn(play, &thisx->world.pos, -4.0f, 4.0f, 4.0f, (Rand_ZeroOne() * 0.09f) + 0.03f);
        }
        ref_func_80ACBDCC(this);
    } else {
        ref_func_80ACBC70(this);
    }
}

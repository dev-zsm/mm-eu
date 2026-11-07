// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gamelupy.h"

void EnGamelupy_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnGamelupy* this = (EnGamelupy*)thisx;

    Actor_SetScale(&this->actor, 0.03f);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 10.0f);
    this->actor.shape.yOffset = 700.0f;
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    this->actor.gravity = -0.5f;
    this->actor.shape.rot.y = Rand_Next();
    this->collectedTimer = 0;
    this->sparklesAngle = 0;
    this->sparklesAngleStep = 0x7D0;
    if (EN_GAMELUPY_GET_TYPE(&this->actor) == ENGAMELUPY_TYPE_BLUE) {
        this->type = ENGAMELUPY_TYPE_BLUE;
    } else {
        this->type = ENGAMELUPY_TYPE_GREEN;
    }
    EnGamelupy_SetupFindSharedMemory(this);
}

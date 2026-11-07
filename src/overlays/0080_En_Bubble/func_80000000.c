// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

void EnBubble_SetDimensions(EnBubble* this, f32 dim) {
    f32 x;
    f32 y;
    f32 z;
    f32 norm;

    this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
    Actor_SetScale(&this->actor, 1.0f);
    this->actor.shape.yOffset = 16.0f;
    this->modelRotSpeed = 16.0f;
    this->modelEllipticity = 0.08f;
    this->modelWidth = dim;
    this->modelHeight = dim;
    x = Rand_ZeroOne();
    y = Rand_ZeroOne();
    z = Rand_ZeroOne();
    this->unk_210 = 1.0f;
    this->unk_214 = 1.0f;
    norm = SQ(x) + SQ(y) + SQ(z);
    this->unk1F8.x = x / norm;
    this->unk1F8.y = y / norm;
    this->unk1F8.z = z / norm;
}

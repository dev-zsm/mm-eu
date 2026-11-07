// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_InitFlameGroup(EnHonotrap* this, PlayState* play) {
    EnHonotrapFlameGroup* flameGroup;
    s32 flameScroll;
    s32 i;

    Actor_SetScale(&this->actor, 0.0001f);
    Collider_InitCylinder(play, &this->collider.cyl);
    Collider_SetCylinder(play, &this->collider.cyl, &this->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&this->actor.colChkInfo, NULL, &sColChkInfoInit);

    flameScroll = Rand_ZeroOne() * 511.0f;
    flameGroup = &this->flameGroup;
    for (i = 0; i < ARRAY_COUNT(flameGroup->flameList); i++) {
        flameGroup->flameList[i].flameScroll = flameScroll;
        flameScroll += (s32)Rand_ZeroFloat(300.0f) + 100;
        flameScroll %= 0x200U;
    }

    Actor_PlaySfx(&this->actor, NA_SE_EV_FLAME_IGNITION);
    EnHonotrap_SetupFlameGroup(this);
}

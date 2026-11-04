// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void SkelAnime_UpdateTranslation(SkelAnime* skelAnime, Vec3f* diff, s16 angle) {
    f32 x;
    f32 z;
    f32 sin;
    f32 cos;

    if (skelAnime->movementFlags & ANIM_FLAG_NOMOVE) {
        diff->z = 0.0f;
        diff->x = 0.0f;
    } else {
        
        x = skelAnime->jointTable[LIMB_ROOT_POS].x - skelAnime->prevTransl.x;
        z = skelAnime->jointTable[LIMB_ROOT_POS].z - skelAnime->prevTransl.z;
        sin = Math_SinS(angle);
        cos = Math_CosS(angle);
        diff->x = x * cos + z * sin;
        diff->z = z * cos - x * sin;
    }

    skelAnime->prevTransl.x = skelAnime->jointTable[LIMB_ROOT_POS].x;
    skelAnime->jointTable[LIMB_ROOT_POS].x = skelAnime->baseTransl.x;
    skelAnime->prevTransl.z = skelAnime->jointTable[LIMB_ROOT_POS].z;
    skelAnime->jointTable[LIMB_ROOT_POS].z = skelAnime->baseTransl.z;

    if (skelAnime->movementFlags & ANIM_FLAG_UPDATE_Y) {
        if (skelAnime->movementFlags & ANIM_FLAG_NOMOVE) {
            diff->y = 0.0f;
        } else {
            diff->y = skelAnime->jointTable[LIMB_ROOT_POS].y - skelAnime->prevTransl.y;
        }
        skelAnime->prevTransl.y = skelAnime->jointTable[LIMB_ROOT_POS].y;
        skelAnime->jointTable[LIMB_ROOT_POS].y = skelAnime->baseTransl.y;
    } else {
        diff->y = 0.0f;
        skelAnime->prevTransl.y = skelAnime->jointTable[LIMB_ROOT_POS].y;
    }
    skelAnime->movementFlags &= ~ANIM_FLAG_NOMOVE;
}

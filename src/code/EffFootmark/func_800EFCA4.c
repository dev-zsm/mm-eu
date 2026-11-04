// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_footmark.h"

void EffFootmark_Add(PlayState* play, MtxF* mf, Actor* actor, u8 id, Vec3f* pos, u16 size, u8 red, u8 green, u8 blue,
                     u16 alpha, u16 alphaChange, u16 fadeOutDelay) {
    s32 i;
    EffFootmark* footmark;
    EffFootmark* destination = NULL;
    EffFootmark* oldest = NULL;
    s32 isNew = true;

    for (footmark = play->footprintInfo, i = 0; i < ARRAY_COUNT(play->footprintInfo); i++, footmark++) {
        if (((actor == footmark->actor) && (footmark->id == id)) && !(footmark->flags & FOOTMARK_FLAG_1)) {
            if (fabsf(footmark->pos.x - pos->x) <= 1) {
                if (fabsf(footmark->pos.z - pos->z) <= 1) {
                    isNew = false;
                    break;
                }
            }

            
            footmark->flags = FOOTMARK_FLAG_1;
        }

        if (footmark->actor == NULL) {
            destination = footmark;
        } else if (destination == NULL) {
            if (((oldest != NULL) && (footmark->age > oldest->age)) || (oldest == NULL)) {
                oldest = footmark;
            }
        }
    }

    if (isNew && ((destination != NULL) || (oldest != NULL))) {
        if (destination == NULL) {
            destination = oldest;
        }
        Matrix_MtxFCopy(&destination->mf, mf);
        destination->actor = actor;
        destination->pos.x = pos->x;
        destination->pos.y = pos->y;
        destination->pos.z = pos->z;
        destination->flags = 0;
        destination->id = id;
        destination->red = red;
        destination->green = green;
        destination->blue = blue;
        destination->alpha = alpha;
        destination->alphaChange = alphaChange;
        destination->size = size;
        destination->fadeOutDelay = fadeOutDelay;
        destination->age = 0;
    }
}

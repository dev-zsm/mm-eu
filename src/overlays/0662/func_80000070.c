// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_swprize.h"

void ref_func_80C253D0(ObjSwprize* this, PlayState* play) {
    Actor* thisx = &this->actor;
    s32 i;
    Actor* collectible;
    Vec3f sp78;
    s32 type = OBJ_SWPRIZE_GET_TYPE(thisx);
    s32 temp_s0 = ref_D_80C257F0[type];

    ref_func_80C25360(this, &sp78);

    if (type == 2) {
        for (i = 0; i < 3; i++) {
            collectible = Item_DropCollectible(play, &thisx->world.pos, temp_s0);
            if (collectible != NULL) {
                if (sp78.y < 0.98f) {
                    collectible->velocity.y = (sp78.y + 1.0f) * 4.0f;
                    collectible->speed = (2.0f * (1.0f - fabsf(sp78.y))) + 2.0f;
                    collectible->world.rot.y = Math_Atan2S_XY(sp78.z, sp78.x) + ref_D_80C257F8[i];
                } else {
                    collectible->world.rot.y = i * (0x10000 / 3);
                }
            }
        }
    } else {
        collectible = Item_DropCollectible(play, &thisx->world.pos, temp_s0);
        if ((collectible != NULL) && (sp78.y < 0.98f)) {
            collectible->velocity.y = (sp78.y + 1.0f) * 4.0f;
            collectible->speed = (2.0f * (1.0f - fabsf(sp78.y))) + 2.0f;
            collectible->world.rot.y = Math_Atan2S_XY(sp78.z, sp78.x);
        }
    }
}

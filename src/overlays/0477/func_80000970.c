// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

s32 ref_func_80B30480(ObjSpidertent* this, PlayState* play, Vec3f* arg2) {
    Player* player = GET_PLAYER(play);
    TriNorm* triNorm;
    s32 i;
    Vec3f sp58;
    f32 sp54;

    if (player->heldItemAction == PLAYER_IA_DEKU_STICK) {
        if (player->unk_B28 > 0) {
            for (i = 0; i < ARRAY_COUNT(this->colliderElements); i++) {
                triNorm = &this->collider.elements[i].dim;

                if (ref_func_80B2FB94(&player->meleeWeaponInfo[0].tip, 6.0f, triNorm, &sp58, &sp54) &&
                    ref_func_80B2FC98(triNorm, &sp58)) {
                    break;
                }
            }

            if (i < ARRAY_COUNT(this->colliderElements)) {
                Math_Vec3f_Copy(arg2, &player->meleeWeaponInfo[0].tip);
                return true;
            }
        }
    }
    return false;
}

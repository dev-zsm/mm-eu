// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

void ref_func_80B30808(ObjSpidertent* this, PlayState* play) {
    s32 phi_s4;
    s32 i;
    ObjSpidertentStruct* ptr2 = &ref_D_80B31350[OBJSPIDERTENT_GET_1(&this->dyna.actor)];
    Vec3f sp70;
    Vec3s* hitPos;
    ColliderTrisElement* trisElem;
    f32 temp_f0;
    s32 phi_s1;
    Vec3f sp54;
    f32 phi_f20;
    s32 phi_s0 = false;

    if (this->collider.base.acFlags & AC_HIT) {
        Player* player = GET_PLAYER(play);

        this->collider.base.acFlags &= ~AC_HIT;
        phi_s1 = 0;
        phi_s4 = -1;
        phi_f20 = FLT_MAX;

        for (i = 0; i < ARRAY_COUNT(this->colliderElements); i++) {
            trisElem = &this->collider.elements[i];

            if (trisElem->base.acElemFlags & ACELEM_HIT) {
                sp54.x = trisElem->base.acDmgInfo.hitPos.x;
                sp54.y = trisElem->base.acDmgInfo.hitPos.y;
                sp54.z = trisElem->base.acDmgInfo.hitPos.z;

                temp_f0 = Math3D_Vec3fDistSq(&sp54, &player->actor.world.pos);
                if (temp_f0 < phi_f20) {
                    phi_f20 = temp_f0;
                    phi_s4 = i;
                }
            }
        }

        if (phi_s4 >= 0) {
            hitPos = &this->collider.elements[phi_s4].base.acDmgInfo.hitPos;

            sp70.x = hitPos->x;
            sp70.y = hitPos->y;
            sp70.z = hitPos->z;
        } else {
            Math_Vec3f_Copy(&sp70, &this->dyna.actor.world.pos);
        }
        phi_s0 = true;
    } else if ((this->dyna.actor.xzDistToPlayer < ptr2->unk_24) && ref_func_80B30480(this, play, &sp70)) {
        phi_s0 = true;
    }

    if (phi_s0) {
        ref_func_80B30410(this, &sp70);
        ref_func_80B30A2C(this);
    } else {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}

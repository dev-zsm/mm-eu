// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

void ref_func_80B300F4(ObjSpidertent* thisx, PlayState* play, TriNorm* triNorm, Vec3f* arg3, f32 arg4, s32 arg5) {
    ObjSpidertent* this = (ObjSpidertent*)thisx;
    ObjSpidertentStruct* spE0 = &ref_D_80B31350[OBJSPIDERTENT_GET_1(&this->dyna.actor)];
    f32 temp_f24;
    f32 phi_f22;
    s32 i;
    f32 temp_f0;
    Vec3f spC4;
    Vec3f spB8;
    Vec3f spAC;
    Vec3f spA0;
    Vec3f sp94;
    Vec3f sp88;
    f32 temp_f2;
    ObjSpidertentStruct2* sp80 = &ref_D_80B313A0[arg5];

    spAC.x = triNorm->plane.normal.x;
    spAC.y = triNorm->plane.normal.y;
    spAC.z = triNorm->plane.normal.z;

    if (triNorm->plane.normal.y < 0.5f) {
        Math3D_Vec3f_Cross(&spAC, &ref_D_80B3140C, &sp88);
    } else {
        Math3D_Vec3f_Cross(&spAC, &ref_D_80B31400, &sp88);
    }

    if (ref_func_80B2FB10(&sp88, &spA0)) {
        phi_f22 = 0.0f;
        temp_f24 = (2 * M_PIf) / sp80->unk_0F;

        for (i = 0; i < sp80->unk_0F; i++) {
            temp_f2 = (Rand_ZeroOne() * temp_f24) + phi_f22;
            Matrix_RotateAxisF(temp_f2, &spAC, MTXMODE_NEW);
            Matrix_MultVec3f(&spA0, &sp94);

            if (arg5 == 0) {
                spC4.x = (sp94.x * arg4) + arg3->x;
                spC4.y = (sp94.y * arg4) + arg3->y;
                spC4.z = (sp94.z * arg4) + arg3->z;
            } else {
                temp_f0 = Rand_ZeroOne();
                temp_f0 = (1.0f - SQ(temp_f0)) * arg4;
                spC4.x = (sp94.x * temp_f0) + arg3->x;
                spC4.y = (sp94.y * temp_f0) + arg3->y;
                spC4.z = (sp94.z * temp_f0) + arg3->z;
            }

            if ((Math3D_Vec3fDistSq(&spC4, &this->dyna.actor.world.pos) < spE0->unk_1C) &&
                ref_func_80B2FC98(triNorm, &spC4)) {
                spB8.x = sp80->unk_08 * sp94.x;
                spB8.y = sp80->unk_08 * sp94.y;
                spB8.z = sp80->unk_08 * sp94.z;

                EffectSsDeadDb_Spawn(play, &spC4, &spB8, &gZeroVec3f, &sp80->unk_10, &sp80->unk_14, sp80->unk_0C, 0,
                                     sp80->unk_0E);
            }

            phi_f22 += temp_f24;
        }
    }
}

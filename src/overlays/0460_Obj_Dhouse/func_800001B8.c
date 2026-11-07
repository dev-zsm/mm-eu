// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B12B38(ObjDhouse* this, PlayState* play) {
    Actor* thisx = &this->dyna.actor;
    s32 i;
    f32 temp_f0;
    CollisionPoly* sp90;
    s32 phi_s3;
    Vec3f sp80;
    s32 bgId;
    ObjDhouseStruct1* ptr;
    ObjDhouseStruct3* ptr3;

    for (i = 0, ptr = &this->unk_160[0], ptr3 = &ref_D_80B13E90[0]; i < ARRAY_COUNT(this->unk_160); i++, ptr3++, ptr++) {
        if (ptr->unk_1E >= 0) {
            if (ptr->unk_1E >= ptr3->unk_26) {
                ptr->unk_0C.y -= 2.5f;

                Math_Vec3f_Scale(&ptr->unk_0C, 0.96f);

                ptr->unk_00.x += ptr->unk_0C.x;
                ptr->unk_00.y += ptr->unk_0C.y;
                ptr->unk_00.z += ptr->unk_0C.z;

                ptr->unk_18.x += ptr3->unk_20.x;
                ptr->unk_18.y += ptr3->unk_20.y;
                ptr->unk_18.z += ptr3->unk_20.z;

                if (ptr->unk_1E == ptr3->unk_26) {
                    ref_func_80B12E7C(this, play, ptr, ptr3);
                }
            }

            phi_s3 = false;
            if (ptr->unk_0C.y < 0.0f) {
                ref_func_80B12A50(ptr, ptr3, &sp80);
                temp_f0 = BgCheck_EntityRaycastFloor5(&play->colCtx, &sp90, &bgId, thisx, &sp80);
                if (((sp80.y - 35.0f) < temp_f0) && (temp_f0 > (BGCHECK_Y_MIN + 1.0f))) {
                    phi_s3 = true;
                }
            }

            if (phi_s3) {
                ptr->unk_1E = -1;
                ref_func_80B13170(this, play, ptr, ptr3);
            } else if (ptr->unk_1E > 60) {
                ptr->unk_1E = -1;
            } else {
                ptr->unk_1E++;
            }
        }
    }
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B047C0(ObjSnowball* this, PlayState* play) {
    static Vec3f ref_D_80B04FD8 = { 0.0f, 1.0f, 0.0f };
    static Vec3f ref_D_80B04FE4 = { 0.0f, 0.0f, 1.0f };
    s32 pad;
    ObjSnowballStruct* ptr;
    Vec3f sp9C;
    s32 bgId;
    s32 i;
    Vec3f sp88;
    f32 sp84;
    f32 phi_f2;
    f32 sp7C;
    Vec3f sp70;

    for (i = 0; i < ARRAY_COUNT(this->unk_1A8); i++) {
        ptr = &this->unk_1A8[i];

        if (!(ptr->unk_2D & 1)) {
            ptr->unk_10 -= 6.0f;
            ptr->unk_10 *= 0.96f;
            if (ptr->unk_10 < -20.0f) {
                ptr->unk_10 = -20.0f;
            }

            ptr->unk_00.x += ptr->unk_0C;
            ptr->unk_00.y += ptr->unk_10;
            ptr->unk_00.z += ptr->unk_14;

            ptr->unk_1C.x += ptr->unk_22;
            ptr->unk_1C.y += ptr->unk_24;
            ptr->unk_1C.z += ptr->unk_26;

            sp9C.x = ptr->unk_00.x;
            sp9C.y = ptr->unk_00.y + 25.0f;
            sp9C.z = ptr->unk_00.z;

            ptr->unk_18 = BgCheck_EntityRaycastFloor5(&play->colCtx, &ptr->unk_28, &bgId, &this->actor, &sp9C);

            if (ptr->unk_10 <= 0.0f) {
                Matrix_RotateZYX(ptr->unk_1C.x, ptr->unk_1C.y, ptr->unk_1C.z, MTXMODE_NEW);
                Matrix_MultVec3f(&ref_D_80B04FE4, &sp88);

                sp84 = this->unk_20C * 60.0f * 0.9f;
                if (sp88.y > 0.0f) {
                    if (Math3D_CosOut(&ref_D_80B04FD8, &sp88, &sp7C)) {
                        phi_f2 = 1.0f;
                    } else {
                        phi_f2 = 1.0f - SQ(sp7C);
                    }

                    if (phi_f2 <= 0.0f) {
                        sp84 = 0.0f;
                    } else {
                        sp84 *= sqrtf(phi_f2);
                    }
                }

                if (((ptr->unk_00.y - sp84) < ptr->unk_18) || (ptr->unk_18 < BGCHECK_Y_MIN + 10.0f)) {
                    ptr->unk_2D |= 1;
                    sp70.x = ptr->unk_00.x;
                    sp70.y = ptr->unk_00.y - sp84;
                    sp70.z = ptr->unk_00.z;
                    ref_func_80B03A80(play, this->unk_20C, &sp70);
                }
            }
        }
    }

    this->unk_208--;

    if ((this->unk_208 <= 0) || ((this->unk_1A8[0].unk_2D & 1) && (this->unk_1A8[1].unk_2D & 1))) {
        if (this->unk_20B != 0) {
            CutsceneManager_Stop(this->actor.csId);
        }

        if (this->actor.home.rot.y == 1) {
            ref_func_80B04B48(this, play);
        } else {
            Actor_Kill(&this->actor);
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(this->unk_1A8); i++) {
            ptr = &this->unk_1A8[i];

            if (ptr->unk_2D & 1) {
                ptr->unk_2C = 0;
            } else if (ptr->unk_2C < 136) {
                ptr->unk_2C += 24;
            } else {
                ptr->unk_2C = 160;
            }
        }
    }
}

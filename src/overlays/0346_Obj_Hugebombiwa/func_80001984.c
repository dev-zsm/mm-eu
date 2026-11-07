// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A55564(ObjHugebombiwa* this, PlayState* play) {
    s32 i;
    EnHugebombiwaStruct* ptr;
    Vec3f spA4;
    s32 pad;
    CollisionPoly* sp9C;
    s32 bgId;
    f32 temp_f0;
    s16 phi_s3 = this->actor.shape.rot.y - 0x4000;

    for (i = 0; i < ARRAY_COUNT(this->unk_190); i++, phi_s3 += 0x666) {
        ptr = &this->unk_190[i];

        if (ptr->unk_24 != 0) {
            continue;
        }

        ptr->unk_18 -= 3.0f;
        if (ptr->unk_18 < -30.0f) {
            ptr->unk_18 = -30.0f;
        }

        ptr->unk_0C.x += (Math_SinS(phi_s3) * 4.0f);
        ptr->unk_0C.y += ptr->unk_18;
        ptr->unk_0C.z += (Math_CosS(phi_s3) * 4.0f);

        ptr->unk_1C.x += ptr->unk_22;

        spA4.x = ptr->unk_0C.x;
        spA4.y = ptr->unk_0C.y + 60.0f;
        spA4.z = ptr->unk_0C.z;

        temp_f0 = BgCheck_EntityRaycastFloor5(&play->colCtx, &sp9C, &bgId, &this->actor, &spA4);
        if ((temp_f0 <= BGCHECK_Y_MIN + 10.0f) || (ptr->unk_0C.y < temp_f0)) {
            this->unk_4B0++;
            ptr->unk_24 = 1;
            ref_func_80A54600(play, &ptr->unk_0C, ptr->unk_18, ptr->unk_00.y * 10.1f);
            if ((play->gameplayFrames % 4) == 0) {
                ObjHugebombiwa_RequestQuakeAndRumble(this, play, (s32)(Rand_ZeroOne() * 5.5f) + 1);
            }
        }
    }

    this->unk_4B2--;
    if ((this->unk_4B0 >= 20) || (this->unk_4B2 <= 0)) {
        CutsceneManager_Stop(this->actor.csId);
        Actor_Kill(&this->actor);
    }
}

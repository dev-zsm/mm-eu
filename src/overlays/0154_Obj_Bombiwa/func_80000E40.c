// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_8093A1F0(ObjBombiwa* this, PlayState* play) {
    s32 pad;
    s32 i;
    Vec3f sp9C;
    ObjBombiwaStruct* ptr;
    CollisionPoly* sp94;
    s32 bgId;
    f32 temp_f0;
    s16 phi_s1;

    for (i = 0, phi_s1 = 0; i < ARRAY_COUNT(this->unk_190); i++, phi_s1 += 0x4000) {
        ptr = &this->unk_190[i];

        if (ptr->unk_1A != 0) {
            continue;
        }

        ptr->unk_10 -= 3.0f;

        ptr->unk_04.x += Math_SinS(phi_s1) * 1.5f;
        ptr->unk_04.y += ptr->unk_10;
        ptr->unk_04.z += Math_CosS(phi_s1) * 1.5f;

        ptr->unk_14.x += 0x5DC;

        sp9C.x = ptr->unk_04.x;
        sp9C.y = ptr->unk_04.y + 30.0f;
        sp9C.z = ptr->unk_04.z;

        temp_f0 = BgCheck_EntityRaycastFloor5(&play->colCtx, &sp94, &bgId, &this->actor, &sp9C);
        if ((temp_f0 <= (BGCHECK_Y_MIN + 10.0f)) || ((ptr->unk_04.y - (200.0f * ptr->unk_00)) < temp_f0)) {
            this->unk_200++;
            ptr->unk_1A = 1;
            ref_func_80939C50(play, &ptr->unk_04);
        }
    }

    this->unk_201--;
    if ((this->unk_200 >= 4) || (this->unk_201 <= 0)) {
        Actor_Kill(&this->actor);
    }
}

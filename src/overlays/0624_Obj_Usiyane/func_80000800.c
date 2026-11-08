// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_usiyane.h"

void ObjUsiyane_Draw(Actor* thisx, PlayState* play) {
    ObjUsiyane* this = (ObjUsiyane*)thisx;
    MtxF mf;

    if (!(this->unk_744 & 1)) {
        Gfx_DrawDListOpa(play, object_obj_usiyane_DL_000838);
    }

    if (!(this->unk_744 & 2)) {
        s32 i;

        for (i = 0; i < ARRAY_COUNT(ref_D_80C08660); i++) {
            Vec3f sp74;

            Matrix_MultVec3f(&ref_D_80C08660[i].pos, &this->unk_710[i]);
            Matrix_MultVec3f(&gZeroVec3f, &sp74);
            this->unk_708 = sp74.x;
            this->unk_70C = sp74.z;
        }
        this->unk_744 |= 2;
    }

    if ((this->unk_744 & 4) && !(this->unk_744 & 8)) {
        s32 i;
        s32 j;

        for (i = 0; i < ARRAY_COUNT(this->unk_168[0]); i++) {
            for (j = 0; j < ARRAY_COUNT(this->unk_168); j++) {
                Matrix_Push();
                SkinMatrix_SetScaleRotateRPYTranslate(&mf, 0.1f, 0.1f, 0.1f, this->unk_168[j][i].unk_18.x,
                                                      this->unk_168[j][i].unk_18.y, this->unk_168[j][i].unk_18.z,
                                                      this->unk_168[j][i].unk_00.x, this->unk_168[j][i].unk_00.y,
                                                      this->unk_168[j][i].unk_00.z);
                Matrix_Put(&mf);
                Gfx_DrawDListOpa(play, object_obj_usiyane_DL_000098);
                Matrix_Pop();
            }
        }
    }
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray3.h"

void ref_func_80B9E5F4(MirRay3* this, PlayState* play, MirRay3Struct* ptr) {
    Player* player = GET_PLAYER(play);
    MtxF* shieldMtx = &player->shieldMf;
    s32 i;
    Vec3f sp88;
    Vec3f sp7C;
    Vec3f sp70;
    CollisionPoly* sp6C;
    f32 sp60[3];

    sp60[0] = -(shieldMtx->mf[2][0] * this->unk_260) * this->unk_214 * 400.0f;
    sp60[1] = -(shieldMtx->mf[2][1] * this->unk_260) * this->unk_214 * 400.0f;
    sp60[2] = -(shieldMtx->mf[2][2] * this->unk_260) * this->unk_214 * 400.0f;

    for (i = 0; i < ARRAY_COUNT(this->unk_218); i++) {
        sp88.x = (shieldMtx->mf[3][0] + (this->unk_218[i].x * shieldMtx->mf[0][0])) +
                 (this->unk_218[i].y * shieldMtx->mf[1][0]);
        sp88.y = (shieldMtx->mf[3][1] + (this->unk_218[i].x * shieldMtx->mf[0][1])) +
                 (this->unk_218[i].y * shieldMtx->mf[1][1]);
        sp88.z = (shieldMtx->mf[3][2] + (this->unk_218[i].x * shieldMtx->mf[0][2])) +
                 (this->unk_218[i].y * shieldMtx->mf[1][2]);

        sp7C.x = sp60[0] + sp88.x;
        sp7C.y = sp60[1] + sp88.y;
        sp7C.z = sp60[2] + sp88.z;

        if (BgCheck_AnyLineTest1(&play->colCtx, &sp88, &sp7C, &sp70, &sp6C, true)) {
            ptr[i].unk_4C = sp6C;
        } else {
            ptr[i].unk_4C = NULL;
        }
    }
}

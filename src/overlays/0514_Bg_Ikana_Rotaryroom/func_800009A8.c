// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B80C88(BgIkanaRotaryroom* this, PlayState* play) {
    s32 pad[5];
    BgIkanaBlock* ikanaBlock = (BgIkanaBlock*)this->unk_204.unk_00;
    Player* player;
    Actor* ptr;
    Actor* ptr2;
    Actor* ptr3;
    s32 i;
    MtxF sp3C;

    Matrix_Push();
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    if (ikanaBlock != NULL) {
        Matrix_Push();

        Matrix_Mult(&this->unk_204.unk_04, MTXMODE_APPLY);
        Matrix_MultZero(&ikanaBlock->dyna.actor.world.pos);
        ref_func_80B80358(&ikanaBlock->dyna.actor.world.pos);
        Matrix_Get(&sp3C);
        Matrix_MtxFToYXZRot(&sp3C, &ikanaBlock->dyna.actor.shape.rot, false);

        Matrix_Pop();
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_248); i++) {
        ptr = this->unk_248[i].unk_00;
        if (ptr != NULL) {
            Matrix_Push();

            Matrix_Mult(&this->unk_248[i].unk_04, MTXMODE_APPLY);
            Matrix_MultZero(&ptr->world.pos);
            ref_func_80B80358(&ptr->world.pos);
            Matrix_Get(&sp3C);
            Matrix_MtxFToYXZRot(&sp3C, &ptr->shape.rot, false);

            Matrix_Pop();
        }
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_2D0); i++) {
        ptr2 = this->unk_2D0[i].unk_00;
        if (ptr2 != NULL) {
            Matrix_Push();

            Matrix_Mult(&this->unk_2D0[i].unk_04, MTXMODE_APPLY);
            Matrix_MultZero(&ptr2->world.pos);
            ref_func_80B80358(&ptr2->world.pos);
            Matrix_Get(&sp3C);
            Matrix_MtxFToYXZRot(&sp3C, &ptr2->shape.rot, false);

            Matrix_Pop();
        }
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_3E0); i++) {
        ptr3 = this->unk_3E0[i].unk_00;
        if (ptr3 != NULL) {
            Matrix_Push();

            Matrix_Mult(&this->unk_3E0[i].unk_04, MTXMODE_APPLY);
            Matrix_MultZero(&ptr3->world.pos);
            ref_func_80B80358(&ptr3->world.pos);
            Matrix_Get(&sp3C);
            Matrix_MtxFToYXZRot(&sp3C, &ptr3->shape.rot, false);

            Matrix_Pop();
        }
    }

    player = GET_PLAYER(play);
    if (player != NULL) {
        Matrix_Push();

        Matrix_Mult(&this->unk_520.unk_00, MTXMODE_APPLY);
        Matrix_MultZero(&player->actor.world.pos);
        Math_Vec3f_Copy(&player->actor.home.pos, &player->actor.world.pos);
        ref_func_80B80358(&player->actor.world.pos);
        Matrix_Get(&sp3C);
        Matrix_MtxFToYXZRot(&sp3C, &player->actor.shape.rot, false);

        Matrix_Pop();
        player->actor.freezeTimer = 2;
    }

    Matrix_Pop();
}

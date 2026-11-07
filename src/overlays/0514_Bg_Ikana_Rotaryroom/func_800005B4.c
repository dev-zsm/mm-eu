// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B80894(BgIkanaRotaryroom* this, PlayState* play) {
    s32 pad[7];
    Actor* actor = this->unk_204.unk_00;
    s32 i;

    Matrix_Push();

    Matrix_RotateZS(-this->dyna.actor.shape.rot.z, MTXMODE_NEW);
    Matrix_RotateXS(-this->dyna.actor.shape.rot.x, MTXMODE_APPLY);
    Matrix_RotateYS(-this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_Translate(-this->dyna.actor.world.pos.x, -this->dyna.actor.world.pos.y, -this->dyna.actor.world.pos.z,
                     MTXMODE_APPLY);

    if (actor != NULL) {
        Matrix_Push();

        Matrix_Translate(actor->world.pos.x, actor->world.pos.y, actor->world.pos.z, MTXMODE_APPLY);
        Matrix_RotateYS(actor->shape.rot.y, MTXMODE_APPLY);
        Matrix_RotateXS(actor->shape.rot.x, MTXMODE_APPLY);
        Matrix_RotateZS(actor->shape.rot.z, MTXMODE_APPLY);
        Matrix_Get(&this->unk_204.unk_04);

        Matrix_Pop();
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_248); i++) {
        this->unk_248[i].unk_00 = NULL;
    }

    actor = play->actorCtx.actorLists[ACTORCAT_DOOR].first;
    i = 0;
    while (actor != NULL) {
        if (ref_func_80B80778(this, play, actor) && (i < 2)) {
            this->unk_248[i].unk_00 = actor;

            Matrix_Push();

            Matrix_Translate(actor->world.pos.x, actor->world.pos.y, actor->world.pos.z, MTXMODE_APPLY);
            Matrix_RotateYS(actor->shape.rot.y, MTXMODE_APPLY);
            Matrix_RotateXS(actor->shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(actor->shape.rot.z, MTXMODE_APPLY);
            Matrix_Get(&this->unk_248[i].unk_04);

            Matrix_Pop();
            i++;
        }
        actor = actor->next;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_2D0); i++) {
        this->unk_2D0[i].unk_00 = NULL;
    }

    actor = play->actorCtx.actorLists[ACTORCAT_ITEMACTION].first;
    i = 0;
    while (actor != NULL) {
        if ((actor->id == ACTOR_EN_TORCH2) && (actor->update != NULL) && (i < ARRAY_COUNT(this->unk_2D0))) {
            this->unk_2D0[i].unk_00 = actor;

            Matrix_Push();

            Matrix_Translate(actor->world.pos.x, actor->world.pos.y, actor->world.pos.z, MTXMODE_APPLY);
            Matrix_RotateYS(actor->shape.rot.y, MTXMODE_APPLY);
            Matrix_RotateXS(actor->shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(actor->shape.rot.z, MTXMODE_APPLY);
            Matrix_Get(&this->unk_2D0[i].unk_04);

            Matrix_Pop();
            i++;
        }
        actor = actor->next;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_3E0); i++) {
        this->unk_3E0[i].unk_00 = NULL;
    }

    actor = play->actorCtx.actorLists[ACTORCAT_ENEMY].first;
    i = 0;
    while (actor != NULL) {
        if ((actor->update != NULL) && (actor->id != ACTOR_EN_WATER_EFFECT) && (i < ARRAY_COUNT(this->unk_3E0))) {
            this->unk_3E0[i].unk_00 = actor;
            this->unk_3E0[i].unk_44 = actor->shape.rot;
            this->unk_3E0[i].unk_4C = 0.0f;

            Matrix_Push();

            Matrix_Translate(actor->world.pos.x, actor->world.pos.y, actor->world.pos.z, MTXMODE_APPLY);
            Matrix_RotateYS(actor->shape.rot.y, MTXMODE_APPLY);
            Matrix_RotateXS(actor->shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(actor->shape.rot.z, MTXMODE_APPLY);
            Matrix_Get(&this->unk_3E0[i].unk_04);

            Matrix_Pop();
            i++;
        }
        actor = actor->next;
    }

    actor = &GET_PLAYER(play)->actor;
    if (actor->update != NULL) {
        this->unk_520.unk_40 = actor->shape.rot;

        Matrix_Push();

        Matrix_Translate(actor->world.pos.x, actor->world.pos.y, actor->world.pos.z, MTXMODE_APPLY);
        Matrix_RotateYS(actor->shape.rot.y, MTXMODE_APPLY);
        Matrix_RotateXS(actor->shape.rot.x, MTXMODE_APPLY);
        Matrix_RotateZS(actor->shape.rot.z, MTXMODE_APPLY);
        Matrix_Get(&this->unk_520.unk_00);

        Matrix_Pop();
    }

    Matrix_Pop();
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_FlameGroup(EnHonotrap* this, PlayState* play) {
    s32 i;
    EnHonotrapFlameGroup* flameGroup = &this->flameGroup;
    f32 var_fs0;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s32 flameScrollDisplacement;
    s32 sp78 = false;
    f32 var_fs0_2;
    Vec3f sp68;
    EnHonotrapFlameElement* flameElem;

    sp80 = fabsf(Math_CosS(Camera_GetCamDirPitch(GET_ACTIVE_CAM(play))));
    flameScrollDisplacement = (s32)(sp80 * -10.5f) - 10;
    Math_StepToF(&flameGroup->unk0, 1.0f, 0.05f);
    if (this->timer <= 40) {
        sp78 = Math_StepToF(&flameGroup->unk4, 1.0f, 0.05f);
    } else if (this->actor.parent == NULL) {
        this->timer = 40;
    }
    for (i = 0; i < ARRAY_COUNT(flameGroup->flameList); i++) {
        flameGroup->flameList[i].isDrawn = false;
    }

    sp88 = Math_SinS(this->actor.shape.rot.y) * 120.0f;
    sp84 = Math_CosS(this->actor.shape.rot.y) * 120.0f;

    flameGroup->unk8 += 0.050f * (1.0f - flameGroup->unk4);

    if (flameGroup->unk8 > 1.0f / 6) {
        flameGroup->unk8 -= 1.0f / 6;
    }
    var_fs0 = flameGroup->unk4 + flameGroup->unk8;

    for (i = 0; i < ARRAY_COUNT(flameGroup->flameList) && (var_fs0 <= flameGroup->unk0); i++) {
        flameElem = &flameGroup->flameList[i];
        flameElem->isDrawn = true;

        flameElem->pos.x = (sp88 * var_fs0) + this->actor.world.pos.x;
        flameElem->pos.y = this->actor.world.pos.y;
        flameElem->pos.z = (sp84 * var_fs0) + this->actor.world.pos.z;

        flameElem->unkC = Math_SinS(TRUNCF_BINANG(var_fs0 * 25486.223f)) * 1.6f;
        if (flameElem->unkC > 1.0f) {
            flameElem->unkC = 1.0f;
        } else if (flameElem->unkC < 0.0f) {
            flameElem->unkC = 0.0f;
        }

        var_fs0 += 1.0f / 6;
        flameElem->unkC *= (0.006f * (((1.0f - flameGroup->unk4) * 0.8f) + 0.2f));
        flameElem->flameScroll += flameScrollDisplacement;
        flameElem->flameScroll %= 0x200U;
    }

    if (sp78 || (this->timer <= 0)) {
        Actor_Kill(&this->actor);
        return;
    }
    temp_fs0 = flameGroup->unk0 * 120.0f;
    temp_fs1 = flameGroup->unk4 * 120.0f;
    Actor_WorldToActorCoords(&this->actor, &sp68, &GET_PLAYER(play)->actor.world.pos);

    if (sp68.z < temp_fs1) {
        sp68.z = temp_fs1;
    } else if (temp_fs0 < sp68.z) {
        sp68.z = temp_fs0;
    }

    var_fs0_2 = Math_SinS(TRUNCF_BINANG(sp68.z * 212.3852f)) * 1.6f;
    if (var_fs0_2 > 1.0f) {
        var_fs0_2 = 1.0f;
    }
    sp80 *= ((1.0f - flameGroup->unk4) * 0.8f) + 0.2f;
    if (sp80 > 0.2f) {
        this->collider.cyl.dim.pos.x =
            TRUNCF_BINANG((Math_SinS(this->actor.shape.rot.y) * sp68.z) + this->actor.world.pos.x);
        this->collider.cyl.dim.pos.y = TRUNCF_BINANG(this->actor.world.pos.y - (24.0f * var_fs0_2));
        this->collider.cyl.dim.pos.z =
            TRUNCF_BINANG((Math_CosS(this->actor.shape.rot.y) * sp68.z) + this->actor.world.pos.z);
        this->collider.cyl.dim.radius = TRUNCF_BINANG(15.0f * var_fs0_2);
        this->collider.cyl.dim.height = TRUNCF_BINANG(37.5f * var_fs0_2);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.tris.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.tris.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.tris.base);
    }
}

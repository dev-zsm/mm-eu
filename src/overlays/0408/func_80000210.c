// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ocarinalift.h"

void ref_func_80AC96D0(ObjOcarinalift* this, PlayState* play) {
    Actor* thisx = &this->dyna.actor;
    Vec3f sp48;
    f32 magnitude;
    f32 phi_fv0;
    f32 phi_fa0;
    s32 paramsC;
    s32 sp34;
    Vec3s* temp_v1_2;

    Actor_PlaySfx_Flagged(thisx, NA_SE_EV_PLATE_LIFT_LEVEL - SFX_FLAG);
    Math_Vec3s_ToVec3f(&sp48, this->pathPoints + this->unk168 + this->unk16C);
    Math_Vec3f_Diff(&sp48, &thisx->world.pos, &thisx->velocity);
    magnitude = Math3D_Vec3fMagnitude(&thisx->velocity);

    if ((magnitude < (this->unk160 * 8.0f)) && (this->unk160 > 2.0f)) {
        phi_fv0 = ((this->unk160 - 2.0f) * 0.1f) + 2.0f;
        phi_fa0 = this->unk160 * 0.03f;
    } else {
        phi_fv0 = this->unk160;
        phi_fa0 = this->unk160 * 0.16f;
    }

    Math_StepToF(&thisx->speed, phi_fv0, phi_fa0);
    if ((thisx->speed + 0.05f) < magnitude) {
        Math_Vec3f_Scale(&thisx->velocity, thisx->speed / magnitude);
        thisx->world.pos.x += thisx->velocity.x;
        thisx->world.pos.y += thisx->velocity.y;
        thisx->world.pos.z += thisx->velocity.z;
    } else {
        paramsC = OBJOCARINALIFT_GET_C(thisx);
        sp34 = true;
        this->unk168 += this->unk16C;
        thisx->speed *= 0.4f;
        if (((this->unk168 >= this->unk164) && (this->unk16C > 0)) || ((this->unk168 <= 0) && (this->unk16C < 0))) {
            if (paramsC == OBJOCARINALIFT_PARAM_0) {
                this->unk16C = -this->unk16C;
                this->timer = 10;
                ref_func_80AC9A68(this);
            } else {
                temp_v1_2 = &this->pathPoints[this->unk164];

                if (this->unk16C > 0) {
                    this->unk168 = 0;
                } else {
                    this->unk168 = this->unk164;
                }

                if (((this->pathPoints[0].x != temp_v1_2->x) || (this->pathPoints[0].y != temp_v1_2->y)) ||
                    (this->pathPoints[0].z != temp_v1_2->z)) {
                    ref_func_80AC99C0(this);
                    DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
                    sp34 = false;
                } else if ((paramsC == OBJOCARINALIFT_PARAM_1) && (this->unk168 == OBJOCARINALIFT_GET_1F(thisx))) {
                    ref_func_80AC9AB8(this);
                }
            }
        } else if ((paramsC == OBJOCARINALIFT_PARAM_1) && (this->unk168 == OBJOCARINALIFT_GET_1F(thisx))) {
            ref_func_80AC9AB8(this);
        }
        if (sp34) {
            ref_func_80AC94C0(this, this->unk168);
        }
    }
}

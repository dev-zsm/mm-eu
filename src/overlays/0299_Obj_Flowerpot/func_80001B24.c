// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1CEF4(ObjFlowerpot* this, PlayState* play) {
    Actor* thisx = &this->actor;
    s32 sp28 = this->collider.elements[0].base.atElemFlags & ATELEM_HIT;

    if (sp28) {
        this->collider.elements[0].base.atElemFlags &= ~ATELEM_ON;
    }

    if (this->unk_1E8 > 0) {
        this->unk_1E8--;
    }

    ref_func_80A1C62C(this, play);

    if ((thisx->bgCheckFlags & (BGCHECKFLAG_GROUND | BGCHECKFLAG_GROUND_TOUCH | BGCHECKFLAG_WALL)) || sp28 ||
        (this->unk_1E8 <= 0)) {
        if (!(this->unk_1EA & 2)) {
            ref_func_80A1B914(this, play);
            ref_func_80A1C0FC(this, play);
            ref_func_80A1B9CC(this, play);
            this->unk_1EA |= 2;
        }
        ref_func_80A1BA44(this, play);
        ref_func_80A1B994(this, play);
        Actor_Kill(thisx);
        return;
    }

    if (thisx->bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) {
        if (!(this->unk_1EA & 2)) {
            ref_func_80A1B914(this, play);
            ref_func_80A1C328(this, play);
            ref_func_80A1B9CC(this, play);
            this->unk_1EA |= 2;
        }
        ref_func_80A1BD80(this, play);
        ref_func_80A1B994(this, play);
        SoundSource_PlaySfxAtFixedWorldPos(play, &thisx->world.pos, 40, NA_SE_EV_DIVE_INTO_WATER_L);
        Actor_Kill(thisx);
        return;
    }

    Actor_MoveWithGravity(thisx);

    if (!(this->unk_1EA & 2)) {
        ref_D_80A1D3F8 += TRUNCF_BINANG(thisx->shape.rot.x * -0.06f);
    } else {
        Math_StepToS(&ref_D_80A1D3F8, 0, 80);
        Math_StepToS(&ref_D_80A1D3FC, 0, 20);
    }

    thisx->shape.rot.x += ref_D_80A1D3F8;
    thisx->shape.rot.y += ref_D_80A1D3FC;

    ref_func_80A1C5E8(this, play);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
}

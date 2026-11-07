// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_viewer.h"

void EnViewer_Init(Actor* thisx, PlayState* play) {
    EnViewer* this = (EnViewer*)thisx;

    this->unk_154 = ref_D_8089F3E0;
    ref_D_8089F3E0++;
    switch (ENVIEWER_GET_3(&this->actor)) {
        case ENVIEWER_PARAM_0:
            this->unk_148 = ENVIEWER_GET_8000(&this->actor) * 40.0f;
            this->unk_150 = (u8)ENVIEWER_GET_1FC(&this->actor) * 40.0f;
            EnViewer_SetupAction(this, ref_func_8089F17C);
            break;

        case ENVIEWER_PARAM_1:
            this->unk_148 = (u16)ENVIEWER_GET_FE00(&this->actor) * 40.0f;
            this->unk_150 = (u8)ENVIEWER_GET_1FC(&this->actor) * 40.0f;
            this->unk_14C = (u16)(this->actor.world.rot.y) * 40.0f;
            EnViewer_SetupAction(this, ref_func_8089F218);
            break;

        case ENVIEWER_PARAM_2:
            this->unk_148 = (u16)ENVIEWER_GET_FE00(&this->actor) * 40.0f;
            this->unk_14C = (u8)ENVIEWER_GET_1FC(&this->actor) * 40.0f;
            EnViewer_SetupAction(this, ref_func_8089F2C4);
            break;

        default:
            break;
    }
}

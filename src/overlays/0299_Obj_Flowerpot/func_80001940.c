// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1CD10(ObjFlowerpot* this) {
    f32 sp1C;

    this->actionFunc = ref_func_80A1CEF4;
    this->unk_1E8 = 64;

    if (this->unk_1EA & 2) {
        sp1C = (Rand_ZeroOne() * 1.2f) - 1.1f;
        if (sp1C < -0.9f) {
            sp1C = -0.9f;
        }
        ref_D_80A1D3F8 = sp1C * 8000.0f;
        ref_D_80A1D3FC = ((Rand_ZeroOne() - 0.5f) * 3800.0f) * (fabsf(sp1C) + 0.1f);
        this->actor.shape.yOffset = -71.5f;
        this->actor.world.pos.y += 7.15f;
    } else {
        sp1C = (Rand_ZeroOne() - 0.78f) * 1.3f;
        if (sp1C < -0.78f) {
            sp1C = -0.78f;
        } else if (sp1C > 0.22000003f) {
            sp1C = 0.22000003f;
        }
        ref_D_80A1D3F8 = sp1C * 6200.0f;
        ref_D_80A1D3FC = (Rand_ZeroOne() - 0.5f) * 4200.0f;
        this->actor.shape.yOffset = -110.0f;
        this->actor.world.pos.y += 11.0f;
    }
}

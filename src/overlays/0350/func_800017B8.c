// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5C918(EnKusa2UnkBssStruct* arg0, EnKusa2UnkBssSubStruct2* arg1) {
    Vec3f sp4C;
    s32 pad;
    s32 pad2;
    Vec3f sp38;
    Vec3f sp2C;
    f32 phi_f0;

    if (arg1->unk_2C > 0) {
        arg1->unk_2C--;

        ref_func_80A5C410(arg0, arg1, &sp4C);

        arg1->unk_10.x += sp4C.x;
        arg1->unk_10.y += sp4C.y;
        arg1->unk_10.z += sp4C.z;

        sp38.x = arg1->unk_10.x * (arg1->unk_1C * 0.06f);
        sp38.x = arg1->unk_10.x * (arg1->unk_1C * 0.06f);
        sp38.y = arg1->unk_10.y * (arg1->unk_1C * 0.06f);
        sp38.z = arg1->unk_10.z * (arg1->unk_1C * 0.06f);

        sp2C.x = SQ(arg1->unk_10.x) * (arg1->unk_1C * 0.004f);
        sp2C.y = SQ(arg1->unk_10.y) * (arg1->unk_1C * 0.004f);
        sp2C.z = SQ(arg1->unk_10.z) * (arg1->unk_1C * 0.004f);

        if (arg1->unk_10.x > 0.0f) {
            phi_f0 = sp2C.x;
        } else {
            phi_f0 = -sp2C.x;
        }
        arg1->unk_10.x -= sp38.x + phi_f0;

        if (arg1->unk_10.y > 0.0f) {
            phi_f0 = sp2C.y;
        } else {
            phi_f0 = -sp2C.y;
        }
        arg1->unk_10.y -= sp38.y + phi_f0;

        if (arg1->unk_10.z > 0.0f) {
            phi_f0 = sp2C.z;
        } else {
            phi_f0 = -sp2C.z;
        }
        arg1->unk_10.z -= sp38.z + phi_f0;

        arg1->unk_04.x += arg1->unk_10.x;
        arg1->unk_04.y += arg1->unk_10.y;
        arg1->unk_04.z += arg1->unk_10.z;
        arg1->unk_20.x += arg1->unk_26.x;
        arg1->unk_20.y += arg1->unk_26.y;
        arg1->unk_20.z += arg1->unk_26.z;
    }
}

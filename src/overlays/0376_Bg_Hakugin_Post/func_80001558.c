// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9C228(BgHakuginPost* this, PlayState* play, BgHakuginPostUnkStruct* unkStruct) {
    s32 val;
    BgHakuginPostUnkStruct1* spC8 = NULL;
    BgHakuginPostUnkStruct1* spC4;
    Vec3f spB8;
    Vec3f spAC;
    Vec3f spA0;
    s32 i;
    f32 temp_f20;
    s16 temp_s0;
    s32 j;

    for (i = 0; i < unkStruct->count; i++) {
        spC4 = spC8;
        spC8 = &unkStruct->unk_0000[i];

        if (unkStruct->unk_0000[i].unk_34 == 2) {
            for (j = 0, val = 0; j < 3; j++, val += 0x5555) {
                temp_f20 = Rand_ZeroOne() * 264.0f;
                temp_s0 = (Rand_Next() % 0x1000) + val;
                spB8.x = Math_SinS(temp_s0) * temp_f20 + spC8->unk_14.x;
                spB8.z = Math_CosS(temp_s0) * temp_f20 + spC8->unk_14.z;

                if (Math3D_Dist1DSq(spB8.x, spB8.z) < SQ(550.0f) + 0.03f) {
                    spB8.x += this->dyna.actor.home.pos.x;
                    spB8.y = spC8->unk_14.y + this->unk_16C + 20.0f;
                    spB8.z += this->dyna.actor.home.pos.z;

                    spAC.x = Math_SinS(spC8->unk_28) * 3.0f;
                    spAC.y = 0.0f;
                    spAC.z = Math_CosS(spC8->unk_28) * 3.0f;

                    spA0.x = spAC.x * -0.08f;
                    spA0.y = 0.2f;
                    spA0.z = spAC.z * -0.08f;

                    ref_func_800B0E48(play, &spB8, &spAC, &spA0, &ref_D_80A9D8E4, &ref_D_80A9D8E8, 0x50,
                                  (s32)(Rand_ZeroOne() * 60.0f) + 110);
                }
            }
        }

        if ((unkStruct->unk_0000[i].unk_2F & 2) && (spC4 != NULL) && ((spC4->unk_34 == 3) || (spC4->unk_34 == 4))) {
            for (j = 0, val = 0; j < 18; j++, val += 0xE38) {
                temp_f20 = (Rand_ZeroOne() * 0.3f + 1.0f) * 220.0f;
                temp_s0 = (Rand_Next() % 0x1000) + val;
                spB8.x = Math_SinS(temp_s0) * temp_f20;
                spB8.z = Math_CosS(temp_s0) * temp_f20;

                spAC.x = spB8.x * (4.0f / 275.0f);
                spAC.y = 0.0f;
                spAC.z = spB8.z * (4.0f / 275.0f);

                spB8.x += unkStruct->unk_0000[i].unk_14.x + this->dyna.actor.home.pos.x;
                spB8.y = unkStruct->unk_0000[i].unk_14.y + this->unk_16C;
                spB8.z += unkStruct->unk_0000[i].unk_14.z + this->dyna.actor.home.pos.z;

                spA0.x = spAC.x * -0.08f;
                spA0.y = 0.2f;
                spA0.z = spAC.z * -0.08f;

                ref_func_800B0E48(play, &spB8, &spAC, &spA0, &ref_D_80A9D8E4, &ref_D_80A9D8E8, 0xC8,
                              (s32)(Rand_ZeroOne() * 70.0f) + 100);
            }
        }
    }
}

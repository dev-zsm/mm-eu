// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9B554(BgHakuginPost* this, PlayState* play, BgHakuginPostUnkStruct* unkStruct,
                   BgHakuginPostUnkStruct1* unkStruct1) {
    f32 spE4 = ref_D_80A9D880[unkStruct1->unk_00].unk_00;
    s32 i;
    s16 val;
    BgHakuginPostUnkStruct2* unkStruct2;
    BgHakuginPostUnkStruct1* unkStruct1Temp;
    f32 temp_f24;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    Vec3f spB8;
    Vec3f spAC;
    Vec3f spA0;
    f32 temp_f28;
    f32 temp_f6;
    s32 pad[2];
    s16 temp_s1_3;

    spB8.x = unkStruct1->unk_14.x + this->dyna.actor.world.pos.x;
    spB8.y = unkStruct1->unk_14.y + this->unk_16C;
    spB8.z = unkStruct1->unk_14.z + this->dyna.actor.world.pos.z;

    spAC.x = Math_SinS(unkStruct1->unk_28) * unkStruct1->unk_20;
    spAC.y = unkStruct1->unk_24;
    spAC.z = Math_CosS(unkStruct1->unk_28) * unkStruct1->unk_20;

    for (i = 0, val = 0; i < 65; i++, val += 0x3F0) {
        unkStruct2 = &unkStruct->unk_02A4[i];
        unkStruct2->unk_00 = Rand_ZeroOne() * 0.038f + 0.002f;
        temp_f24 = Math_SinS(val);
        temp_f28 = Math_CosS(val);
        temp_f20 = Rand_ZeroOne();
        temp_f20 = (1.0f - SQ(temp_f20)) * 198.0f;
        unkStruct2->unk_04.x = temp_f24 * temp_f20 + spB8.x;
        unkStruct2->unk_04.y = Rand_ZeroOne() * spE4 + spB8.y;
        unkStruct2->unk_04.z = temp_f28 * temp_f20 + spB8.z;

        temp_f0 = unkStruct2->unk_00 - 0.002f;
        temp_f22 = temp_f0 * -(450.0f / 19.0f) + 1.0f;
        unkStruct2->unk_10.x = Rand_ZeroOne() * 60.0f;
        temp_f20 = temp_f0 * (10.0f / 19.0f) + 0.06f;

        unkStruct2->unk_10.x = ((unkStruct2->unk_10.x - 30.0f) + temp_f24 * 50.0f) * temp_f22 + spAC.x * temp_f20;
        unkStruct2->unk_10.y = (Rand_ZeroOne() * 102.0f + 18.0f) * temp_f22 + spAC.y * temp_f20;
        temp_f0 = spAC.z;
        unkStruct2->unk_10.z = ((Rand_ZeroOne() * 60.0f - 30.0f) + temp_f28 * 50.0f) * temp_f22 + temp_f0 * temp_f20;
        unkStruct2->unk_1C = 0.90999997f - (0.04f - unkStruct2->unk_00) * (500.0f / 19.0f) * 0.02f;
        unkStruct2->unk_20.x = (s32)Rand_Next() >> 0x10;
        unkStruct2->unk_20.y = (s32)Rand_Next() >> 0x10;
        unkStruct2->unk_20.z = (s32)Rand_Next() >> 0x10;
        unkStruct2->unk_26 = (Rand_Next() % 0x4000) - 0x1FFF;
        unkStruct2->unk_28 = (Rand_Next() % 0x2000) - 0xFFF;
        unkStruct2->unk_2A = (Rand_Next() % 0x2000) - 0xFFF;
        unkStruct2->unk_2C = (Rand_Next() % 0x20) + 0x4B;
        unkStruct2->unk_2D = 2;
    }

    for (i = 0, val = 0; i < 22; i++, val += 0xBA2) {
        temp_f20 = Rand_ZeroOne() * 60.0f + 220.0f;
        spA0.x = Math_SinS(val) * temp_f20 + spB8.x;
        spA0.y = (Rand_ZeroOne() * 1.2f - 0.1f) * spE4 + spB8.y;
        spA0.z = Math_CosS(val) * temp_f20 + spB8.z;
        ref_func_800B0E48(play, &spA0, &gZeroVec3f, &ref_D_80A9D8EC, &ref_D_80A9D8E4, &ref_D_80A9D8E8,
                      ((s32)Rand_Next() >> 0x1A) + 0x82, ((s32)Rand_Next() >> 0x1A) + 0x6E);
    }

    unkStruct1Temp = ref_func_80A9B32C(unkStruct, unkStruct1);
    if (unkStruct1Temp != NULL) {
        temp_f6 = this->unk_16C + ref_func_80A9B2B8(unkStruct) - 40.0f;
        spB8.x = unkStruct1Temp->unk_14.x + this->dyna.actor.world.pos.x;
        spB8.y = unkStruct1Temp->unk_14.y + this->unk_16C;
        spB8.z = unkStruct1Temp->unk_14.z + this->dyna.actor.world.pos.z;

        for (i = 65, val = 0; i < ARRAY_COUNT(unkStruct->unk_02A4); i++, val += 0x4A7) {
            unkStruct2 = &unkStruct->unk_02A4[i];
            unkStruct2->unk_00 = Rand_ZeroOne() * 0.007f + 0.002f;
            temp_s1_3 = (Rand_Next() % 0x800) + val;
            temp_f24 = Math_SinS(temp_s1_3);
            temp_f28 = Math_CosS(temp_s1_3);
            unkStruct2->unk_04.x = temp_f24 * 225.5f + spB8.x;
            if (i & 1) {
                unkStruct2->unk_04.y = Rand_ZeroOne() * ref_D_80A9D880[unkStruct1Temp->unk_00].unk_00 + spB8.y;
            } else {
                unkStruct2->unk_04.y = temp_f6 - Rand_ZeroOne() * 350.0f;
            }
            unkStruct2->unk_04.z = temp_f28 * 225.5f + spB8.z;
            unkStruct2->unk_10.x = Rand_ZeroOne() + temp_f24 * 7.0f;
            unkStruct2->unk_10.y = 0.0f;
            unkStruct2->unk_10.z = Rand_ZeroOne() + temp_f28 * 7.0f;
            unkStruct2->unk_1C = 0.90999997f - (0.04f - unkStruct2->unk_00) * (500.0f / 19.0f) * 0.075f;
            unkStruct2->unk_20.x = (s32)Rand_Next() >> 0x10;
            unkStruct2->unk_20.y = (s32)Rand_Next() >> 0x10;
            unkStruct2->unk_20.z = (s32)Rand_Next() >> 0x10;
            unkStruct2->unk_26 = (Rand_Next() % 0x2000) - 0xFFF;
            unkStruct2->unk_28 = (Rand_Next() % 0x2000) - 0xFFF;
            unkStruct2->unk_2A = (Rand_Next() % 0x2000) - 0xFFF;
            unkStruct2->unk_2C = (Rand_Next() % 0x20) + 0x41;
            unkStruct2->unk_2D = 0;
        }
    }
    unkStruct->unk_1924 = true;
}

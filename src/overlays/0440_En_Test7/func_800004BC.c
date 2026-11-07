// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateFeatherType1(PlayState* play, OwlWarpFeather* feather) {
    static Vec3f sUnitVecY = { 0.0f, 1.0f, 0.0f };
    static Vec3f sUnitVecZ = { 0.0f, 0.0f, 1.0f };
    static MtxF sFeatherRotMf;
    static Vec3f sFeatherAccel;
    static Vec3f sFeatherUnused;
    s32 swayAngleX = feather->unk_04 % 41;
    s32 swayAngleY = (feather->unk_04 + 7000) % 41;
    s32 sp24 = false;

    SkinMatrix_SetRotateRPY(&sFeatherRotMf, feather->rot.x, feather->rot.y, feather->rot.z);
    SkinMatrix_Vec3fMtxFMultXYZ(&sFeatherRotMf, &sUnitVecY, &sFeatherAccel);
    SkinMatrix_Vec3fMtxFMultXYZ(&sFeatherRotMf, &sUnitVecZ, &sFeatherUnused);

    if (feather->rot.x < 0x3448) {
        feather->rot.x += 0x384;
    } else if (feather->rot.x >= 0x4BB9) {
        feather->rot.x -= 0x384;
    } else {
        feather->rot.x = (Math_SinS(((f32)swayAngleX * 0xFFFF) / 41.0f) * 2000.0f) + 0x4000;
    }

    if (feather->rot.y < -0xBB8) {
        feather->rot.y += 0x384;
    } else if (feather->rot.y > 0xBB8) {
        feather->rot.y -= 0x384;
    } else {
        sp24 = true;
        feather->rot.y = Math_SinS(((f32)swayAngleY * 0xFFFF) / 41.0f) * 2000.0f;
    }

    if (sp24 == true) {
        if (sFeatherAccel.y < 0.0f) {
            feather->velocity.x += sFeatherAccel.x * 0.5f;
            feather->velocity.y += sFeatherAccel.y * 0.5f + 0.08f;
            feather->velocity.z += sFeatherAccel.z * 0.5f;
        } else {
            feather->velocity.x += -sFeatherAccel.x * 0.5f;
            feather->velocity.y += -sFeatherAccel.y * 0.5f + 0.08f;
            feather->velocity.z += -sFeatherAccel.z * 0.5f;
        }
    } else if (sFeatherAccel.y < 0.0f) {
        feather->velocity.x += sFeatherAccel.x * 0.2f;
        feather->velocity.y += sFeatherAccel.y * 0.2f + 0.08f;
        feather->velocity.z += sFeatherAccel.z * 0.2f;
    } else {
        feather->velocity.x += -sFeatherAccel.x * 0.2f;
        feather->velocity.y += -sFeatherAccel.y * 0.2f + 0.08f;
        feather->velocity.z += -sFeatherAccel.z * 0.2f;
    }

    feather->pos.x += feather->velocity.x;
    feather->pos.y += feather->velocity.y;
    feather->pos.z += feather->velocity.z;
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_arrow_fire.h"

void FireArrow_SetQuadVerticies(ArrowFire* this) {
    static Vec3f ref_D_80922284 = { 100.0f, 700.0f, 0.0f };
    static Vec3f ref_D_80922290 = { 400.0f, 27.0f, 0.0f };
    static Vec3f ref_D_8092229C = { -100.0f, 700.0f, 0.0f };
    static Vec3f ref_D_809222A8 = { -400, 27.0f, 0.0f };
    static Vec3f ref_D_809222B4 = { 0.0f, 700.0f, 100.0f };
    static Vec3f ref_D_809222C0 = { 0.0f, 27.0f, 400.0f };
    static Vec3f ref_D_809222CC = { 0.0f, 700.0f, -100.0f };
    static Vec3f ref_D_809222D8 = { 0.0f, 27.0f, -400.0f };
    Vec3f sp44;
    Vec3f sp38;
    Vec3f sp2C;
    Vec3f sp20;

    Matrix_MultVec3f(&ref_D_80922284, &sp44);
    Matrix_MultVec3f(&ref_D_80922290, &sp38);
    Matrix_MultVec3f(&ref_D_8092229C, &sp2C);
    Matrix_MultVec3f(&ref_D_809222A8, &sp20);
    Collider_SetQuadVertices(&this->collider1, &sp44, &sp38, &sp2C, &sp20);
    Matrix_MultVec3f(&ref_D_809222B4, &sp44);
    Matrix_MultVec3f(&ref_D_809222C0, &sp38);
    Matrix_MultVec3f(&ref_D_809222CC, &sp2C);
    Matrix_MultVec3f(&ref_D_809222D8, &sp20);
    Collider_SetQuadVertices(&this->collider2, &sp44, &sp38, &sp2C, &sp20);
}

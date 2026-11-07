// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_paper.h"

void EnPaper_InitConfettiPiece(EnPaper* this, EnPaperConfetto* piece) {
    
    Matrix_RotateZYX(Rand_Next(), Rand_Next(), Rand_Next(), MTXMODE_NEW);
    Matrix_MultVec3f(&sUnitVecZ, &piece->rotAxis);

    
    piece->pos = this->actor.world.pos;
    piece->pos.x += Rand_Centered() * 4.0f;
    piece->pos.y += Rand_Centered() * 4.0f;
    piece->pos.z += Rand_Centered() * 4.0f;

    
    
    piece->velocity = this->actor.velocity;
    piece->velocity.x += Rand_Centered() * 9.0f;
    piece->velocity.y += Rand_ZeroOne() * 6.0f;
    piece->velocity.z += Rand_Centered() * 9.0f;

    
    piece->angle = Rand_Next();
    piece->angVel = (Rand_Next() >> 4) + (0x10000 / 180);

    
    Matrix_RotateAxisS(piece->angle, &piece->rotAxis, MTXMODE_NEW);
    Matrix_MultVec3f(&sUnitVecZ, &piece->normal);
}

// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_paper.h"

void EnPaper_FlyConfettiPiece(EnPaper* this, EnPaperConfetto* piece) {
    f32 cos = Math_CosS(piece->angle);
    f32 sin = Math_SinS(piece->angle);
    f32 versin = 1.0f - cos;

    if (piece->pos.y < (this->actor.floorHeight - 40.0f)) {
        return;
    }

    
    piece->velocity.y += this->actor.gravity;

    
    piece->velocity.x -= 0.2f * fabsf(piece->normal.x) * (piece->velocity.x + this->windForce.x);
    piece->velocity.y -= 0.2f * fabsf(piece->normal.y) * (piece->velocity.y + this->windForce.y);
    piece->velocity.z -= 0.2f * fabsf(piece->normal.z) * (piece->velocity.z + this->windForce.z);

    
    piece->angle += piece->angVel;

    
    piece->pos.x += piece->velocity.x;
    piece->pos.y += piece->velocity.y;
    piece->pos.z += piece->velocity.z;

    
    
    piece->normal.x = (versin * piece->rotAxis.x * piece->rotAxis.z) - (piece->rotAxis.y * sin);
    piece->normal.y = (versin * piece->rotAxis.y * piece->rotAxis.z) + (piece->rotAxis.x * sin);
    piece->normal.z = (versin * piece->rotAxis.z * piece->rotAxis.z) + cos;
}

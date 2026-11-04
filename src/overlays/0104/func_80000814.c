// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wood02.h"

void EnWood02_Destroy(Actor* thisx, PlayState* play) {
    EnWood02* this = (EnWood02*)thisx;

    if ((this->actor.params < WOOD_BUSH_GREEN_SMALL) || (this->actor.params == WOOD_TREE_SPECIAL)) {
        Collider_DestroyCylinder(play, &this->collider);
    }
}

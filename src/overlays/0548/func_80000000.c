// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_yasi.h"

void ObjYasi_Init(Actor* thisx, PlayState* play) {
    ObjYasi* this = (ObjYasi*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gPalmTreeCol);

    this->dyna.actor.home.rot.y = 0;

    if (PALM_TREE_IS_WIDE(thisx)) {
        this->dyna.actor.scale.x = 0.2f;
        this->dyna.actor.scale.z = 0.2f;
    }
}

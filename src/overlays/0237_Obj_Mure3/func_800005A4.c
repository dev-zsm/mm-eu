// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure3.h"

void ref_func_8098F5E4(ObjMure3* this, PlayState* play) {
    static ObjMure3SpawnFunc sSpawnFuncs[] = { ref_func_8098F040, ref_func_8098F110, ref_func_8098F220 };

    if (Math3D_Dist1DSq(this->actor.projectedPos.x, this->actor.projectedPos.z) < SQ(1150.0f)) {
        this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        sSpawnFuncs[OBJMURE3_PARAM_RUPEEINDEX(&this->actor)](this, play);
        ref_func_8098F66C(this);
    }
}

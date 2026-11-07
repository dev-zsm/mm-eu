// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

s32 ref_func_80A1E394(CollisionContext* colCtx, f32* arg1, CollisionPoly** polyOut, s32* bgId, Vec3f* arg4,
                  ObjSpinyroll* this) {
    return BgCheck_EntityCheckCeiling(colCtx, arg1, arg4, 24.0f, polyOut, bgId, &this->dyna.actor);
}

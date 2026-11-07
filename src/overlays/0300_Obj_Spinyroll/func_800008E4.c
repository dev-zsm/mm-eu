// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

s32 ref_func_80A1E334(CollisionContext* colCtx, f32* arg1, CollisionPoly** polyOut, s32* bgId, Vec3f* arg4,
                  ObjSpinyroll* this) {
    f32 temp_f0 = BgCheck_EntityRaycastFloor5(colCtx, polyOut, bgId, &this->dyna.actor, arg4);

    *arg1 = temp_f0;
    return *arg1 > (BGCHECK_Y_MIN + 1);
}

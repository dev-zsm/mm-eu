// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

void BgCheck_GetSubdivisionMaxBounds(CollisionContext* colCtx, Vec3f* pos, s32* sx, s32* sy, s32* sz) {
    f32 dx = pos->x - colCtx->minBounds.x;
    f32 dy = pos->y - colCtx->minBounds.y;
    f32 dz = pos->z - colCtx->minBounds.z;

    *sx = dx * colCtx->subdivLengthInv.x;
    *sy = dy * colCtx->subdivLengthInv.y;
    *sz = dz * colCtx->subdivLengthInv.z;

    if (((s32)colCtx->subdivLength.x - BGCHECK_SUBDIV_OVERLAP < (s32)dx % (s32)colCtx->subdivLength.x) &&
        (*sx < colCtx->subdivAmount.x - 1)) {
        *sx += 1;
    }

    if (((s32)colCtx->subdivLength.y - BGCHECK_SUBDIV_OVERLAP < (s32)dy % (s32)colCtx->subdivLength.y) &&
        (*sy < colCtx->subdivAmount.y - 1)) {
        *sy += 1;
    }

    if (((s32)colCtx->subdivLength.z - BGCHECK_SUBDIV_OVERLAP < (s32)dz % (s32)colCtx->subdivLength.z) &&
        (*sz < colCtx->subdivAmount.z - 1)) {
        *sz += 1;
    }
}

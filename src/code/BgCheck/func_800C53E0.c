// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK BgCheck_CheckLineImpl(s32, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, f32, s32); /* extern */
s32 BgCheck_GetBccFlags(s32, s32, s32, s32, s32);         /* extern */

s32 BgCheck_EntityLineTest2(struct CollisionContext *colCtx, struct Vec3f *posA, struct Vec3f *posB, struct Vec3f *posResult, struct CollisionPoly **outPoly, s32 checkWall, s32 checkFloor, s32 checkCeil, s32 checkOneFace, s32 *bgId, struct Actor *actor) {
    BgCheck_CheckLineImpl(colCtx, 2, 0, posA, posB, posResult, outPoly, bgId, actor, 1.0f, BgCheck_GetBccFlags(checkWall, checkFloor, checkCeil, checkOneFace, 1));
}

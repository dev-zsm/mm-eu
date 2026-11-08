// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 DynaPoly_SetBgActor(s32, s32, void *, s32);           /* extern */
M2C_UNK CollisionHeader_GetVirtual(M2C_UNK, s32 *);              /* extern */

void DynaPolyActor_LoadMesh(struct PlayState *play, struct DynaPolyActor *dynaActor, struct CollisionHeader *meshHeader) {
    s32 sp1C;

    sp1C = 0;
    CollisionHeader_GetVirtual(meshHeader, &sp1C);
    M2C_FIELD(dynaActor, s32 *, 0x144) = DynaPoly_SetBgActor(play, (u8 *)play + 0x880, dynaActor, sp1C);
}

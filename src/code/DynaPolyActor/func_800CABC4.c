// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 DynaPoly_SetBgActor(s32, s32, void *, s32);           /* extern */
M2C_UNK CollisionHeader_GetVirtual(M2C_UNK, s32 *);              /* extern */

void DynaPolyActor_LoadMesh(s32 arg0, void *arg1, M2C_UNK arg2) {
    s32 sp1C;

    sp1C = 0;
    CollisionHeader_GetVirtual(arg2, &sp1C);
    M2C_FIELD(arg1, s32 *, 0x144) = DynaPoly_SetBgActor(arg0, arg0 + 0x880, arg1, sp1C);
}

// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK DynaSSNodeList_Init(s32, void *);                 /* extern */
M2C_UNK DynaPoly_NullPolyList(void *);                      /* extern */
M2C_UNK DynaPoly_NullVtxList(void *);                      /* extern */
M2C_UNK DynaPoly_InitWaterBoxList(void *);                      /* extern */

void DynaPoly_Init(s32 arg0, s8 *arg1) {
    *arg1 = 1;
    DynaPoly_NullPolyList(arg1 + 0x13F0);
    DynaPoly_NullVtxList(arg1 + 0x13F4);
    DynaPoly_InitWaterBoxList(arg1 + 0x13F8);
    DynaSSNodeList_Init(arg0, arg1 + 0x1400);
}

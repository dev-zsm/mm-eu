// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF910(s32, s32, u16);               /* extern */
u16 DynaSSNodeList_GetNextNodeIdx(s32 *);                           /* extern */

void DynaSSNodeList_SetSSListHead(s32 *arg0, u16 *arg1, s32 arg2) {
    u16 sp1E;
    u16 temp_v0;

    temp_v0 = DynaSSNodeList_GetNextNodeIdx(arg0);
    sp1E = temp_v0;
    func_800BF910(*arg0 + (temp_v0 * 4), arg2, *arg1);
    *arg1 = sp1E;
}

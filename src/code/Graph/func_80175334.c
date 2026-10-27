// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80081B34(M2C_UNK *);                   /* extern */
M2C_UNK func_80081D04(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801EF968;
extern M2C_UNK D_801EF978;

void Graph_Destroy(s32 arg0) {
    func_80081B34(&D_801EF978);
    func_80081D04(&D_801EF968);
}

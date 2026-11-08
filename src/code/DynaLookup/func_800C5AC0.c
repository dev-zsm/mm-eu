// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF92C(s32);                         /* extern */

void DynaLookup_ResetLists(struct DynaLookup *dynaLookup) {
    func_800BF92C((u8 *)dynaLookup + 2);
    func_800BF92C((u8 *)dynaLookup + 4);
    func_800BF92C((u8 *)dynaLookup + 6);
}

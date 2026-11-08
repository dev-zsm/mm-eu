// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK PreRender_AntiAliasFilter();                            /* extern */
M2C_UNK PreRender_DivotFilter(void *);                      /* extern */

void PreRender_ApplyFilters(struct PreRender *this) {
    if ((M2C_FIELD(this, s32 *, 0x18) == 0) || (M2C_FIELD(this, s32 *, 0x14) == 0)) {
        M2C_FIELD(this, s8 *, 0x4D) = 0;
        return;
    }
    M2C_FIELD(this, s8 *, 0x4D) = 1;
    PreRender_AntiAliasFilter();
    PreRender_DivotFilter(this);
    M2C_FIELD(this, s8 *, 0x4D) = 2;
}

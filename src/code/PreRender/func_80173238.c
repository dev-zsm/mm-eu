// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80085468(M2C_UNK *);                   /* extern */
M2C_UNK Slowly_Destroy(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801EE690;
extern s32 D_801EE850;
extern M2C_UNK D_801EE858;

void PreRender_ApplyFiltersSlowlyDestroy(s32 arg0) {
    if (D_801EE850 != 0) {
        func_80085468(&D_801EE858);
        Slowly_Destroy(&D_801EE690);
        D_801EE850 = 0;
    }
}

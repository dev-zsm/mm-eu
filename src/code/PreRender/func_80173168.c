// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80085390(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK, s32, M2C_UNK *); /* extern */
M2C_UNK func_80085468(M2C_UNK *);                   /* extern */
M2C_UNK Slowly_Init(M2C_UNK *, M2C_UNK *, M2C_UNK *, void *, s32); /* extern */
M2C_UNK Slowly_Destroy(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801D74F0;
extern M2C_UNK D_801EE690;
extern s32 D_801EE850;
extern M2C_UNK D_801EE858;
extern M2C_UNK D_801EE878;
extern M2C_UNK D_801EF878;
extern M2C_UNK PreRender_ApplyFilters;

void PreRender_ApplyFiltersSlowlyInit(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x18) != 0) && (M2C_FIELD(arg0, s32 *, 0x14) != 0)) {
        if (D_801EE850 != 0) {
            func_80085468(&D_801EE858);
            Slowly_Destroy(&D_801EE690);
        }
        M2C_FIELD(arg0, s8 *, 0x4D) = 1;
        func_80085390(&D_801EE858, &D_801EE878, &D_801EF878, 0, 0x100, &D_801D74F0);
        Slowly_Init(&D_801EE690, &D_801EF878, &PreRender_ApplyFilters, arg0, 0);
        D_801EE850 = 1;
    }
}

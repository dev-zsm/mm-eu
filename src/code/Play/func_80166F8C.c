// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Play_ConvertRgba16ToIntensityImage(M2C_UNK *, s32, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
M2C_UNK PreRender_ApplyFilters(void *);                      /* extern */
extern M2C_UNK D_80780000;

void Play_TakePictoPhoto(void *arg0) {
    PreRender_ApplyFilters(arg0);
    Play_ConvertRgba16ToIntensityImage(&D_80780000, M2C_FIELD(arg0, s32 *, 0x14), 0x140, 0x50, 0x40, 0xEF, 0xAF, 8);
}

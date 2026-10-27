// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 MapDisp_GetSizeOfMapITex(s32);                             /* extern */
M2C_UNK func_8017A0BC(M2C_UNK *, s32, s32, s32);    /* extern */
extern M2C_UNK D_9B8000;

void MapDisp_GetMapITexture(s32 arg0, s32 arg1) {
    if (MapDisp_GetSizeOfMapITex(arg1) != 0) {
        func_8017A0BC(&D_9B8000, arg1, arg0, MapDisp_GetSizeOfMapITex(arg1));
    }
}

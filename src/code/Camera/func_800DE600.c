// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Distortion_Request(M2C_UNK);                     /* extern */
M2C_UNK Distortion_RemoveRequest(M2C_UNK);                     /* extern */

s32 Camera_UpdateHotRoom(void *arg0) {
    Distortion_RemoveRequest(1);
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x8C), u8 *, 0x186E2) == 3) {
        Distortion_Request(1);
    }
    return 1;
}

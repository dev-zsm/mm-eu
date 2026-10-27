// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_800CB938();                                /* extern */
M2C_UNK Distortion_SetDuration(M2C_UNK);                     /* extern */
s32 Distortion_GetType();                                /* extern */
M2C_UNK Distortion_Request(M2C_UNK);                     /* extern */

s32 Camera_SetSwordDistortion(void) {
    s32 temp_v0;

    temp_v0 = func_800CB938();
    switch (temp_v0) {                              /* irregular */
    case 1:
        if (Distortion_GetType() != 0x40) {
            Distortion_Request(0x40);
            Distortion_SetDuration(0xC);
        }
        break;
    case 2:
        if (Distortion_GetType() != 0x80) {
            Distortion_Request(0x80);
            Distortion_SetDuration(5);
        }
        break;
    case 3:
        if (Distortion_GetType() != 0x100) {
            Distortion_Request(0x100);
            Distortion_SetDuration(0xF);
        }
        break;
    }
    return 1;
}

// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Lights_FreeNode(void *);                      /* extern */

void LightContext_RemoveLight(s32 arg0, void **arg1, void *arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != NULL) {
        temp_v0 = M2C_FIELD(arg2, void **, 4);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, void **, 8) = (void *) M2C_FIELD(arg2, void **, 8);
        } else {
            *arg1 = M2C_FIELD(arg2, void **, 8);
        }
        temp_v0_2 = M2C_FIELD(arg2, void **, 8);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, void **, 4) = (void *) M2C_FIELD(arg2, void **, 4);
        }
        Lights_FreeNode(arg2);
    }
}

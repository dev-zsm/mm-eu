// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Actor_TextboxIsClosing(void *);                          /* extern */
extern M2C_UNK EnAObj_Idle;

void EnAObj_Talk(void *arg0) {
    if (Actor_TextboxIsClosing(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &EnAObj_Idle;
    }
}

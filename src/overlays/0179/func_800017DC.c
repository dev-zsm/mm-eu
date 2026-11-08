// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0179.h"

typedef struct {
    u8 pad[4];
    s16 f4;
} H0179;

H0179 *func_800F1E3C();
void func_800DF8D4();

void func_800017DC(u8 *arg0, u8 *arg1) {
    s8 t;

    if (M2C_FIELD(arg0, s16 *, 0x542) != 0) {
        t = M2C_FIELD(arg0, s8 *, 0x38);
        if (t != -1) {
            func_800DF8D4(M2C_FIELD(arg1, s32 *, 0x800), func_800F1E3C(t)->f4);
        }
    }
}

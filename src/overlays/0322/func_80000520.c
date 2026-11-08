#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0322.h"
extern s8 D_801E6FC3[];
s32 func_80A1E96C(s32 a, s32 b);

s32 func_80000520(s32 a, s32 idx) {
    s8 t;

    if (idx <= 0 || idx >= 5) {
        return 0;
    }
    t = D_801E6FC3[idx];
    return t - func_80A1E96C(a, idx) + 10;
}

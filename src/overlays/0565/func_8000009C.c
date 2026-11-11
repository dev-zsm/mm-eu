// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0565.h"

extern u8 D_801E7E1D;
extern u8 D_801E7E1E;

s32 func_8000009C(s16 arg0) {
    switch (arg0) {
    case 0:
        if (D_801E7E1D & 4) {
            return 1;
        }
        return 0;
    case 1:
        if (D_801E7E1D & 0x80) {
            return 1;
        }
        return 0;
    case 2:
        if (D_801E7E1E & 1) {
            return 1;
        }
        return 0;
    case 3:
        if (D_801E7E1E & 2) {
            return 1;
        }
        return 0;
    case 4:
        if (D_801E7E1E & 4) {
            return 1;
        }
        return 0;
    case 5:
        if (D_801E7E1E & 8) {
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}

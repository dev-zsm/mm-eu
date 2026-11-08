#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0571.h"
void func_80BB78AC(u8 *a, s32 b);

s32 func_80000690(u8 *a, s32 b) {
    switch (M2C_FIELD(a, u8 *, 0x1DC)) {
        case 1:
            func_80BB78AC(a, 0);
            break;
        case 2:
            func_80BB78AC(a, 4);
            break;
    }
    return 0;
}

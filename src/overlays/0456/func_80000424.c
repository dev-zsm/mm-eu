// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0456.h"

s16 func_800F1E68(s16, u8 *);                     /* extern */

void func_80000424(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x282) = (s16) M2C_FIELD(thisx, s8 *, 0x38);
    M2C_FIELD(thisx, s16 *, 0x284) = func_800F1E68(M2C_FIELD(thisx, s16 *, 0x282), thisx);
    M2C_FIELD(thisx, s16 *, 0x286) = func_800F1E68(M2C_FIELD(thisx, s16 *, 0x284), thisx);
}

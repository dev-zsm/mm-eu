// FLAGS: -O2 -g0
#include "types.h"

u32 func_80087100(u32 *a) {
    return *a = *a * 0x19660D + 0x3C6EF35F;
}

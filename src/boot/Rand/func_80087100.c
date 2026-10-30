// FLAGS: -O2 -g0
#include "libm.h"

u32 Rand_Next_Variable(u32 *rand) {
    return *rand = *rand * 0x19660D + 0x3C6EF35F;
}

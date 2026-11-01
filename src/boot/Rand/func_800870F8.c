// FLAGS: -O2 -g0
#include "sdk/libm.h"

void Rand_Seed_Variable(u32 *rand, u32 seed) {
    *rand = seed;
}

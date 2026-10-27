// FLAGS: -O2 -g0
#include "types.h"

void Rand_Seed_Variable(u32 *a, u32 v) {
    *a = v;
}

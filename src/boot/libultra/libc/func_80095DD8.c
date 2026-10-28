// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

f32 __ull_to_f(u64 arg0) {
    return (f32)arg0;
}

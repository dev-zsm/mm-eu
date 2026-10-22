// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"
f32 __ll_to_f(s64 arg0) {
    return (f32)arg0;
}

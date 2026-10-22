// FLAGS: -O2 -g0
#include "types.h"

f64 floor(f64 arg0) {
    return (f64)(s32)arg0;
}

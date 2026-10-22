// FLAGS: -O2 -g0
#include "types.h"

f32 floorf(f32 arg0) {
    return (f32)(s32)arg0;
}

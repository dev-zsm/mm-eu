#include "types.h"
#include "code_funcs.h"

f32 OLib_ClampMinDist(f32 val, f32 min) {
    if (val < 0.0f) {
        return (-min < val) ? -min : val;
    }
    return (val < min) ? min : val;
}

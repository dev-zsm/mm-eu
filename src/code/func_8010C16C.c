#include "types.h"

f32 OLib_ClampMaxDist(f32 value, f32 max) {
    if (value < 0.0f) {
        return (value < -max) ? -max : value;
    }
    return (max < value) ? max : value;
}

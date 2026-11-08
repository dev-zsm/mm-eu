// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0440.h"

void EnTest7_InitWindCapsule(void *windCapsule) {
    M2C_FIELD(windCapsule, f32 *, 0) = 0.0f;
    M2C_FIELD(windCapsule, f32 *, 4) = 0.0f;
    M2C_FIELD(windCapsule, f32 *, 8) = 1.0f;
    M2C_FIELD(windCapsule, f32 *, 0xC) = 1.0f;
    M2C_FIELD(windCapsule, s16 *, 0x10) = 0;
}

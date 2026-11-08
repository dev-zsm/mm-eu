// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void AudioEffects_InitAdsr(struct AdsrState *adsr, struct EnvelopePoint *envelope, s16 *volOut) {
    M2C_FIELD(adsr, s8 *, 0) = 0;
    M2C_FIELD(adsr, s16 *, 2) = 0;
    M2C_FIELD(adsr, s32 *, 0x1C) = envelope;
    M2C_FIELD(adsr, f32 *, 4) = 0.0f;
    M2C_FIELD(adsr, f32 *, 0x10) = 0.0f;
    M2C_FIELD(adsr, f32 *, 8) = 0.0f;
}

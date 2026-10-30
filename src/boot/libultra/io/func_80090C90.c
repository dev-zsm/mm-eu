// FLAGS: -O2 -g0
#include "os_vi.h"
#include "os_sp.h"

s32 osAiSetFrequency(u32 frequency) {
    s32 dacRate;
    u32 lo;
    u32 period;
    f32 f;

    f = ((f32) D_80098048[0] / (f32) frequency) + 0.5f;
    period = (u32) f;
    if (period < 0x84U) {
        return -1;
    }
    lo = period / 66U;
    dacRate = lo & 0xFF;
    if ((u8)lo >= 0x11) {
        dacRate = 0x10;
    }
    IO_WRITE(AI_DACRATE_REG, period - 1);
    IO_WRITE(AI_BITRATE_REG, dacRate - 1);
    return D_80098048[0] / (s32) period;
}

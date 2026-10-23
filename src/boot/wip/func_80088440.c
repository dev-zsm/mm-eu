// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 m[16];
} Mtx_;

void guScale(Mtx_ *m, f32 x, f32 y, f32 z) {
    s32 e1;
    s32 e2;
    s32 e3;

    m->m[1] = 0;
    m->m[3] = 0;
    m->m[4] = 0;
    m->m[6] = 0;
    m->m[9] = 0;
    m->m[11] = 0;
    m->m[12] = 0;
    m->m[14] = 0;
    m->m[15] = 0;
    e1 = x * 65536.0f;
    e2 = y * 65536.0f;
    e3 = z * 65536.0f;
    m->m[0] = (u32)e1 >> 16 << 16;
    m->m[8] = e1 << 16;
    m->m[10] = e2 & 0xFFFF;
    m->m[2] = (u32)e2 >> 16;
    m->m[5] = (u32)e3 >> 16 << 16;
    m->m[13] = e3 << 16;
    m->m[7] = 1;
}

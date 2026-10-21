// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f64 D_80099690;
extern void func_8008B7A0(f32 *mf);
extern f32 func_800920E0(f32 x);
extern f32 func_800884F0(f32 x);

void func_8008ABF0(f32 *mf, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 sinv;
    f32 cosv;
    f32 radians;
    f32 cot;
    s32 i;
    u32 n;

    func_8008B7A0(mf);
    radians = (f32)((f64)fovy * D_80099690) / 2.0f;
    cosv = func_800920E0(radians);
    sinv = func_800884F0(radians);
    cot = cosv / sinv;
    mf[11] = -1.0f;
    mf[5] = cot;
    mf[10] = (near + far) / (near - far);
    mf[14] = 2.0f * near * far / (near - far);
    mf[0] = cot / aspect;
    mf[15] = 0.0f;
    for (i = 0; i < 16; i++) {
        mf[i] = mf[i] * scale;
    }
    if (perspNorm != NULL) {
        if ((f64)(near + far) <= 2.0) {
            *perspNorm = 0xFFFF;
        } else {
            n = (u32)((f64)0x20000 / (f64)(near + far));
            if (n == 0) {
                n = 1;
            }
            *perspNorm = (u16)n;
        }
    }
}

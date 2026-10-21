// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80090050(f32 *m, f32 x, f32 y, f32 z, f32 s, f32 tx, f32 ty, f32 tz);
void func_800958E0(f32 *m, s32 arg);

void func_800901F8(s32 arg0, f32 x, f32 y, f32 z, f32 s, f32 tx, f32 ty, f32 tz) {
    f32 sp28[16];

    func_80090050(sp28, x, y, z, s, tx, ty, tz);
    func_800958E0(sp28, arg0);
}

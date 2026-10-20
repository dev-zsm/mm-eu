#include "types.h"
void func_80086BA0(f32 x);
f32 sqrtf(f32 x);

void func_80086C88(f32 arg0) {
    func_80086BA0(sqrtf(1.0f - arg0 * arg0));
}

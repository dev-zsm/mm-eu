// FLAGS: -O2 -g0
#include "types.h"

extern u64 func_80088B48(u64 a, u64 b);
extern void func_80087B00(u64 a);

void func_80087C60(u32 a) {
    func_80087B00(func_80088B48((u64)a, 0x2CB4178));
}

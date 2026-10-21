// FLAGS: -O2 -g0
#include "types.h"
void func_800871FC(s32 a0, void *a1);
void func_80087224(s32 a0);
void func_80087560(s32 a0, void *a1);
void func_80087634(s32 a0, void *a1) {
    func_800871FC(a0, a1);
    func_80087560(a0, a1);
    func_80087224(a0);
}

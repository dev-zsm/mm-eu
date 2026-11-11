// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0100.h"

s32 func_80137C58(u8 *, f32);
void func_800B8C4C();
void func_800B8D94();

void func_80000294(u8 *arg0) {
    if (func_80137C58(arg0 + 0x144, 0.0f) != 0 || func_80137C58(arg0 + 0x144, 5.0f) != 0) {
        func_800B8C4C(arg0, 0x38C9);
    }
    func_800B8D94(arg0, 0x30CF);
}

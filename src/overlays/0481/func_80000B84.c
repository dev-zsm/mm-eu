#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0481.h"
void func_800FFCBC(s16 *a, s16 b, s32 c, s32 d, s32 e);

void func_80000B84(s16 *p) {
    s16 t = *p & 0x3FFF;
    s16 r = *p & 0xC000;

    if (t > 0x2000) {
        r += 0x4000;
    }
    func_800FFCBC(p, r, 1, 0xAAA, 0xB6);
}

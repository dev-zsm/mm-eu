#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0573.h"
s32 func_80BB9C4C(u8 *a);
void func_80BB9D98(u8 *a);
void func_800E2500(u8 *a, u8 *b, u8 *c);

void func_8000087C(u8 *a, u8 *play) {
    if (func_80BB9C4C(a) != 0) {
        func_80BB9D98(a);
    } else {
        func_800E2500(play, play + 0x18884, a + 0x15C);
    }
}

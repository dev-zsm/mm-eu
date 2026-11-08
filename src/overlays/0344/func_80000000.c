#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0344.h"
void func_8013A8E0(u8 *a, u8 *b, s32 c, u8 *d, u8 *e, f32 f, f32 g, s32 h);

void func_80000000(u8 *a, u8 *play) {
    func_8013A8E0(a, play, 0xA, play + 0x3C, play + 0x30, 120.0f, 480.0f, 0x38E3);
}

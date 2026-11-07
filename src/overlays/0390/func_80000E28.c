#include "types.h"
#include "m2c_compat.h"
void func_8013A8E0(u8 *a, u8 *b, s32 c, u8 *d, u8 *e, f32 f, f32 g, s32 h);

void func_80000E28(u8 *a, u8 *play) {
    func_8013A8E0(a, play, 2, play + 0x3C, play + 0xBC, 50.0f, 500.0f, -1);
}

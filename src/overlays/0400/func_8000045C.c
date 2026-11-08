#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0400.h"
void func_8013A8E0(u8 *a, u8 *b, s32 c, u8 *d, u8 *e, f32 f, f32 g, s32 h);

void func_8000045C(u8 *a, u8 *play) {
    func_8013A8E0(a, play, 3, play + 0x3C, play + 0xBC, 280.0f, 1800.0f, -1);
}

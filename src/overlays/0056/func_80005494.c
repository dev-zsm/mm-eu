#include "types.h"
typedef struct { u8 pad0[0x6A]; s16 a6A; } Q;
extern Q *D_801EB7E0;
void func_800FEE3C(u8 *, f32, f32);
void func_80005494(u8 *this) {
    func_800FEE3C(this + 0xAD0, 0, (f32)D_801EB7E0->a6A / 100.0f);
}

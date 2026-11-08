#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0614.h"
extern u8 D_80BE5024[];
void func_80BE3234(u8 *a, s32 b, f32 c);
void func_80BE33FC(u8 *a);

void func_800020C4(u8 *a) {
    func_80BE3234(a, 3, 1.0f);
    M2C_FIELD(a, s16 *, 0x338) = 0xF;
    M2C_FIELD(a, s16 *, 0x33A) = 0x28;
    func_80BE33FC(a);
    M2C_FIELD(a, void **, 0x284) = D_80BE5024;
}

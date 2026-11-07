#include "types.h"
#include "m2c_compat.h"
f32 func_800FF72C(u8 *a, u8 *b);
void func_80BB4208(u8 *a);

void func_80000464(u8 *a, u8 *play) {
    u8 *p = M2C_FIELD(play, u8 **, 0x1CCC);

    if (func_800FF72C(p + 0x24, a + 8) < 200.0f) {
        func_80BB4208(a);
    }
}

#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0509.h"
typedef struct { s32 x, y, z; } V;

void func_800016C8(u8 *a, u8 *play) {
    u8 *q = M2C_FIELD(play, u8 **, 0x1CCC);
    u8 *p = a + 0x308;

    if (M2C_FIELD(a, u32 *, 0x2F4) & 0x20) {
        M2C_FIELD(q, V *, 0x24) = *(V *)p;
        M2C_FIELD(q, V *, 0x108) = *(V *)p;
    }
}

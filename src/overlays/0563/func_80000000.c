#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0563.h"
typedef struct { s32 x, y, z; } V;
void func_800B6564(u8 *a, f32 b);

void func_80000000(u8 *a, u8 *play) {
    func_800B6564(a, 1.0f);
    M2C_FIELD(a, s16 *, 0x144) = 0;
    M2C_FIELD(a, V *, 0x24) = M2C_FIELD(((u8 **)(play + 0x800))[M2C_FIELD(play, s16 *, 0x810)], V *, 0x5C);
}

#include "types.h"
#include "m2c_compat.h"
typedef struct { u32 w; u8 pad[0x40]; } R;
typedef struct { u8 pad0[0x17D98]; R r[1]; } PS;
extern u32 D_801EFA18;
void func_80137070(u8 *a);

void func_800008FC(u8 *a, PS *play) {
    D_801EFA18 = play->r[M2C_FIELD(a, s32 *, 0x248)].w + 0x80000000;
    func_80137070(a + 0x144);
}

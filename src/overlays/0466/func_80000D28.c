#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0466.h"
extern u8 D_80B03954[];
void func_80B032D8(u8 *a, s32 b);

void func_80000D28(u8 *a) {
    M2C_FIELD(a, s16 *, 0x2CC) = M2C_FIELD(a, s16 *, 0x2CA) = 0;
    M2C_FIELD(a, s16 *, 0x2D2) = 0;
    func_80B032D8(a, 7);
    M2C_FIELD(a, s16 *, 0x2C8) = 1;
    M2C_FIELD(a, void **, 0x2C0) = D_80B03954;
}

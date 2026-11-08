#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0615.h"
extern u8 D_80BE6DBC[];
void func_80BE5EDC(u8 *a, s32 b, f32 c);

void func_80001134(u8 *a) {
    M2C_FIELD(a, s16 *, 0x116) = 0x72D;
    func_80BE5EDC(a, 9, 1.0f);
    M2C_FIELD(a, s16 *, 0x2CA) = 4;
    M2C_FIELD(a, void **, 0x284) = D_80BE6DBC;
}

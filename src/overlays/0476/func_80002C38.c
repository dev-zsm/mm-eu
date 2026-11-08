#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"
extern u8 D_80B12A5C[];
void func_80B13610(u8 *a);

void func_80002C38(u8 *a, u8 *play) {
    M2C_FIELD(a, void (**)(u8 *, u8 *), 0x188)(a, play);
    if ((void *)D_80B12A5C != M2C_FIELD(a, void **, 0x188)) {
        M2C_FIELD(a, s16 *, 0x190) += 1;
    }
    func_80B13610(a);
}

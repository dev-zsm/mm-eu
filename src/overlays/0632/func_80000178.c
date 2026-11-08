#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0632.h"
extern u8 D_6001384[];
extern u8 D_600AD98[];
extern u8 D_80BF4F3C[];
void func_80137828(u8 *a, u8 *b, f32 c);

void func_80000178(u8 *a) {
    if ((void *)D_6001384 == M2C_FIELD(a, void **, 0x14C)) {
        func_80137828(a + 0x144, D_600AD98, 5.0f);
    }
    M2C_FIELD(a, void **, 0x2A8) = D_80BF4F3C;
}

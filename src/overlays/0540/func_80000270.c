#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0540.h"
extern u8 D_600C880[];
extern u8 D_6003AA8[];
void func_80137934(u8 *a, u8 *b, f32 c);

void func_80000270(u8 *a, u8 *play) {
    u8 *dl = D_600C880;

    if (M2C_FIELD(play, s16 *, 0xA4) == 0x12) {
        dl = D_6003AA8;
    }
    func_80137934(a + 0x144, dl, -4.0f);
}

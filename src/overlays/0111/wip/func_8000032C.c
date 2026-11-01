#include "types.h"
extern struct { u8 p[0x3F58]; s16 x; } D_801E6EF0;
extern void func_800E0FAC();
void func_8000032C(u8 *a, s32 b) {
    if (D_801E6EF0.x != 0) {
        D_801E6EF0.x = 0;
    }
    func_800E0FAC(b, a + 0x190);
}

#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0533.h"
void func_800E0FAC(u8 *a, u8 *b, s32 c, u8 *d);
void func_800C625C(u8 *a, u8 *b, s32 c);

void func_80000848(u8 *a, u8 *play, s32 c) {
    if (!(M2C_FIELD(a, s16 *, 0x1C) & 0x80)) {
        func_800E0FAC(play, a + 0x15C, c, a);
    }
    func_800C625C(play, play + 0x880, M2C_FIELD(a, s32 *, 0x144));
}

#include "types.h"
typedef struct { u8 pad0[0x3F58]; s16 a3F58; } G;
extern G D_801E6EF0;
void func_800E0FAC();
void func_8000032C(u8 *thisx, s32 play2) {
    u8 *this = thisx;
    s32 play = play2;
    if (D_801E6EF0.a3F58 != 0) {
        D_801E6EF0.a3F58 = 0;
    }
    func_800E0FAC(play, this + 0x190);
}

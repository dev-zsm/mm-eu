// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"

typedef struct {
    u8 pad0[0x34];
    s16 unk34;
    s16 unk36;
    s8 unk38;
    u8 pad39[0x37];
    u8 unk70[1];
} Save;
extern u8 D_801C2D3E;
extern u8 D_801C2D39;
extern Save D_801E6EF0;
s32 func_800A7B70(s16 a0) {
    s16 new_var;
    if (((a0 == 4) || (a0 == 0x19)) || (a0 == 0xB)) {
        if (D_801E6EF0.unk70[D_801C2D3E] == 0xFF) {
            goto fail;
        }
    }
    if ((((a0 == 5) || (a0 == 8)) || (a0 == 9)) || (a0 == 0xA)) {
        if (D_801E6EF0.unk70[D_801C2D39] == 0xFF) {
            goto fail;
        }
    }
    if ((a0 == 0xE) || (a0 == 0xF)) {
        if (D_801E6EF0.unk38 == 0) {
            fail:
            return -1;

        }
    }
    if ((a0 == 3) && ((new_var = D_801E6EF0.unk34) == D_801E6EF0.unk36)) {
        return 0;
    }
    dummy_label_86165: ;
    return a0;
}

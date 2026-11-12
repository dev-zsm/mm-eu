#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1C]; s16 unk1C; u8 pad1E[0x172]; void *unk190; } S_arg0;
typedef struct { u8 pad0[0x16936]; u16 unk16936; u8 pad16938[0x2]; u16 unk1693A; } S_arg1;

extern M2C_UNK D_80958544;

void func_80000290(S_arg0 *arg0, S_arg1 *arg1) {
    s32 temp_v0;
    u16 temp_a2;

    temp_v0 = arg0->unk1C & 0xFF;
    if (arg1->unk16936 == 3) {
        temp_a2 = arg1->unk1693A;
        switch (temp_a2) {                          /* irregular */
            case 10:
                if (temp_v0 == 0x41) {
                arg0->unk190 = &D_80958544;
                arg1->unk16936 = 4U;
                return;
                }
                break;
            case 11:
                if (temp_v0 == 0x40) {
                arg0->unk190 = &D_80958544;
                arg1->unk16936 = 4U;
                }
                break;
        }
    }
}

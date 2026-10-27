#include "types.h"

extern void *THA_AllocTailAlign16(void *tha, s32 size);
extern void *D_801F3640;
extern void *D_801F3644;

void Matrix_Init(u8 *state) {
    D_801F3640 = THA_AllocTailAlign16(state + 0x74, 0x500);
    D_801F3644 = D_801F3640;
}

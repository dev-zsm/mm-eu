#include "types.h"
#include "generated/overlays/0280.h"
typedef struct { s16 x[3]; } S6;
void func_80000348(u8 *a, s32 b) {
    *(S6 *)(a + 0xBC) = *(S6 *)(a + 0x30);
}

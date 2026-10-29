#include "types.h"
typedef struct { s16 x[3]; } S6;
void func_80000C40(u8 *a) {
    *(S6 *)(a + 0x278) = *(S6 *)(a + 0x27E);
    *(s16 *)(a + 0x276) = *(s16 *)(a + 0xBE);
}

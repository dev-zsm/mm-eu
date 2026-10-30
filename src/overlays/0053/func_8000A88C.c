#include "types.h"
extern void (*D_80816088[])();
void func_8000A88C(u8 *a0) {
    D_80816088[*(s16 *)(a0 + 0x24486)]();
}

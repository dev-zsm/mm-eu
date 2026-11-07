#include "types.h"
#include "generated/overlays/0602.h"
extern u8 D_6000000[];
u8 *func_80100304();
void EffLastday_SetVtxAlpha(s16 a0) {
    u8 *p = func_80100304(D_6000000);
    p[0xF] = a0;
    p[0x3F] = a0;
    p[0x4F] = a0;
    p[0x5F] = a0;
}

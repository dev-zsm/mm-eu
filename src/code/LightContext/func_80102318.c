#include "types.h"

void LightContext_SetAmbientColor(u8 *a0, u8 a1, u8 a2, u8 a3) {
    a0[4] = a1;
    a0[5] = a2;
    a0[6] = a3;
}

#include "types.h"
extern u8 D_801E6F10;
extern u8 D_801C0C58[];
u8 Player_GetStrength(void) { u8 i = D_801E6F10; return D_801C0C58[i]; }

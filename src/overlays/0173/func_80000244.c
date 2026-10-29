#include "types.h"
extern s32 D_801E6FFC[][7];
s32 func_80000244(s16 *a0) { return D_801E6FFC[a0[0xA4/2]][0] & 7; }

#include "types.h"
typedef struct { u8 p[0xB72]; u16 h; } S;
u16 func_800005E8(S *a0, u16 a1) { return a1 + a0->h; }

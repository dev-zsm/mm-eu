#include "types.h"
typedef struct { u8 p[0x94]; u16 u94; } T;
typedef struct { u8 p[0xA68]; T *uA68; u8 q[0x106]; u16 uB72; } S;
u16 func_8000063C(S *a0, u16 a1) { return a1 + a0->uB72 + a0->uA68->u94; }

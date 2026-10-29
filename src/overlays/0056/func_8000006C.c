#include "types.h"
typedef struct { u8 pad[0x144]; } Z;
typedef struct { u8 pad[0x1CCC]; u32 *p; } B;
s32 func_8000006C(B *a) { u32 *p = a->p; return (p[1] & 0x100) == 0x100; }

#include "types.h"
typedef struct { u8 pad[0x148]; u8 unk148; } B;
typedef struct { u8 pad[0x124]; B *unk124; } A;
s32 func_80000B9C(A *a0) { B *b = a0->unk124; if (b->unk148 < 200) { return 1; } return 0; }

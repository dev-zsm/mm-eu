#include "types.h"
typedef struct { s32 pad[6]; s16 unk18; } B;
typedef struct { u8 pad[0x2A0]; B *unk2A0; } A;
s16 func_80000654(A *a) {
    if (a->unk2A0 != 0) {
        return a->unk2A0->unk18;
    }
    return 0;
}

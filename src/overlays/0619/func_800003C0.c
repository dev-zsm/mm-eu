#include "types.h"
typedef struct { u8 pad[0xA6C]; u32 unkA6C; } P;
typedef struct { u8 pad[0x1CCC]; P *unk1CCC; } B;
typedef struct { u8 pad[0x190]; void (*unk190)(); } A;
void func_800003C0(A *a, B *b) {
    P *p = b->unk1CCC;
    if (!(p->unkA6C & 0x10000282)) {
        a->unk190();
    }
}

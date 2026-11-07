#include "types.h"
typedef struct A A;
struct A { s16 id; u8 pad[0x28E]; s16 a290; s16 a292; };
typedef struct { s16 id; } Q;
typedef struct { u8 pad0[0x1CE4]; u8* head; } P;
typedef struct { u8 pad0[0x3F4]; void* a3F4; } B;
s32 func_800014E4(B *this, P *play) {
    u8 *a = play->head;
    while (a != NULL) {
        if (*(s16 *)a == 0x1EE && *(s16 *)(a + 0x292) == *(s16 *)(a + 0x290)) {
            this->a3F4 = a;
            return 1;
        }
        a = *(u8 **)(a + 0x12C);
    }
    return 0;
}

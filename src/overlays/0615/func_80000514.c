#include "types.h"
typedef struct { u8 pad[0x2F9]; u8 unk2F9; } A;
extern void func_80BE741C();
s32 func_80000514(A *a) {
    if (a->unk2F9 & 2) {
        func_80BE741C();
        return 1;
    }
    return 0;
}

#include "types.h"
typedef struct { u8 pad[0x138]; s32 unk138; } P;
typedef struct { u8 pad[0x120]; P *unk120; } A;
extern void func_800B6490();
extern void func_800B8D94();
void func_8000171C(A *a, s32 b) {
    if (a->unk120->unk138 == 0) {
        func_800B6490();
        return;
    }
    func_800B8D94(a, 0x321F);
}

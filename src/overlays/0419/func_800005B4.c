#include "types.h"

typedef struct { u8 pad0[0x1C]; s16 unk1C; } A;
extern void func_800BDD44();
extern s32 D_80AB8018[];

void func_800005B4(A *a, s32 b) {
    func_800BDD44(b, D_80AB8018[a->unk1C & 3], b, a);
}

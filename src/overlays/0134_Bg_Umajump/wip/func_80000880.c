#include "types.h"

typedef struct {
    u8 pad0[0x144];
    s32 v;
} T;

extern void func_800BDD44();
extern u8 D_6001220[];

void BgUmajump_Draw(T *a, s32 b) {
    if (a->v != -1) {
        func_800BDD44(b, D_6001220, b);
    }
}

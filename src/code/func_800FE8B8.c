#include "types.h"

typedef struct {
    char pad0[0xC];
    u16 unkC;
} Unk801E6EF0;

extern u16 D_801BE6EC;
extern Unk801E6EF0 D_801E6EF0;

void func_800FE8B8(void) {
    if (D_801BE6EC != 0) {
        D_801E6EF0.unkC += D_801BE6EC;
        D_801BE6EC = 0;
    }
}

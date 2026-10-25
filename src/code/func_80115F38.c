#include "types.h"

typedef struct {
    u8 pad0[0x39];
    s8 unk39;
    u8 pad3A[0x3F2A - 0x3A];
    s16 unk3F2A;
    u8 pad3F2C[2];
    s16 unk3F2E;
    u8 pad3F30[4];
    s16 unk3F34;
} SaveContext;
extern SaveContext D_801E6EF0;
void func_80115F38(s32 arg0, s16 delta) {
    s8 *p = &D_801E6EF0.unk39;
    s8 new_var;
    new_var = *p;
    if (new_var < D_801E6EF0.unk3F2E) {
        D_801E6EF0.unk3F34 += delta;
        D_801E6EF0.unk3F2A = 1;
    }
}

#include "types.h"

typedef struct {
    u8 pad0[0x20];
    u8 unk20;
    u8 pad21[0x2B];
    u8 tab[4][4];
} Data;
typedef struct {
    u8 pad0[0x16B60];
    u8 *unk16B60;
} Ctx;
extern Data D_801E6EF0;
extern u8 D_9FEE70[];
extern void func_8017A0BC(u8 *, u8, u8 *, s32);
void func_80112A3C(Ctx *a0, u8 a1) {
    int idx;
    s32 v1;
    if (!a1) {
        if (D_801E6EF0.unk20 == 4) {
            v1 = 0;
        } else {
            v1 = D_801E6EF0.unk20;
        }
        idx = D_801E6EF0.tab[v1][a1];
    } else {
        idx = D_801E6EF0.tab[0][a1];
    }
    func_8017A0BC(D_9FEE70, idx, a0->unk16B60 + (a1 << 12), 0x1000);
}

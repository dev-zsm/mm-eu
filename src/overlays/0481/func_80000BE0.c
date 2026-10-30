#include "types.h"
typedef struct { u8 pad[0xB7]; u8 unkB7; u8 pad2[0x8C]; void *unk144; } A;
extern u8 D_80B1C7D0;
extern void func_80B1C7BC();
void func_80000BE0(A *a) {
    if (a->unk144 != &D_80B1C7D0 && a->unkB7 == 0) {
        func_80B1C7BC();
    }
}

#include "types.h"
extern u8 D_80B41680[];
typedef struct {
    u8 pad0[0x30]; s16 x30; s16 x32; s16 x34;
    u8 pad1[0x5C]; s16 x92;
    u8 pad2[0x28]; s16 xBC; s16 xBE; s16 xC0;
    u8 pad4[0x82]; void *x144;
} A;
void func_80001630(A *a, s32 b) {
    a->xBC = 0;
    a->xC0 = 0;
    a->xBE = a->x92;
    a->x30 = a->x30;
    a->x32 = a->x32;
    a->x34 = a->x34;
    a->x144 = D_80B41680;
}

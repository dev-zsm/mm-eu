#include "types.h"
typedef struct A { u8 pad[0x160]; void (*unk160)(struct A *); } A;
void BgBreakwall_Update(A *a) {
    a->unk160(a);
}

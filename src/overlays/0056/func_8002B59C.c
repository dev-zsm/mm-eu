#include "types.h"

typedef struct {
    u8 pad0[0x248];
    void *unk248;
} A;

extern u8 D_400E120[];
void func_8082D744();
void func_800B8BDC();

void func_8002B59C(A *a) {
    if (a->unk248 == D_400E120) {
        func_8082D744(a, 0xD0);
        func_800B8BDC(a, 0x6042);
    }
}

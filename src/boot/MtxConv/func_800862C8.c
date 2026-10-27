// FLAGS: -O2 -g0
#include "types.h"

extern void guMtxL2F(void);

void MtxConv_L2F(void) {
    guMtxL2F();
}

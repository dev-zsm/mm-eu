// FLAGS: -O2 -g0
#include "sdk/gu.h"

void MtxConv_L2F(MtxF mf, Mtx *mtx) {
    guMtxL2F(mf, mtx);
}

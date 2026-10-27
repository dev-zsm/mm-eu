// FLAGS: -O2 -g3 -mips2
#include "types.h"

void SubS_SetOfferMode(u16 *arg0, u16 arg1, u16 arg2) {
    *arg0 = (*arg0 & ~arg2) | arg1;
}

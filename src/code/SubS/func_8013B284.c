// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void SubS_SetOfferMode(u16 *flags, u16 offerMode, u16 mask) {
    *flags = (*flags & ~mask) | offerMode;
}

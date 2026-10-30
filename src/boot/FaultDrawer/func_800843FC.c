// FLAGS: -O2 -g3 -mips2
#include "faultdrawer.h"

void FaultDrawer_SetCharPad(s8 padW, s8 padH) {
    D_80096D80->charWPad = padW;
    D_80096D80->charHPad = padH;
}

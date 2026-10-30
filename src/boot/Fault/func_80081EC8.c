// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_PadCallback(Input *input) {
    func_80177194(input, 0);
}

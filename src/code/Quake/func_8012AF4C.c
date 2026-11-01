// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s16 *Quake_RequestImpl();                               /* extern */

s16 Quake_Request(void) {
    return *Quake_RequestImpl();
}

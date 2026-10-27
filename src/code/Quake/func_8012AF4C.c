// FLAGS: -O2 -g3 -mips2
#include "types.h"

s16 *Quake_RequestImpl();                               /* extern */

s16 Quake_Request(void) {
    return *Quake_RequestImpl();
}

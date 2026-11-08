// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0142.h"

M2C_UNK func_8090AD14(u8 *);                      /* extern */

void ObjKibako_Update(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x144)();
    func_8090AD14(thisx);
}

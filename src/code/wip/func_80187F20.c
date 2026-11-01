// FLAGS: -O1 -g3 -mips2
#include "types.h"
s32 func_80187B4C(u8 *);
s32 func_80187D04(void);
s32 func_80187F20(void) {
    u8 sp1F;
    func_80187B4C(&sp1F);
    if ((sp1F & 2) == 2) {
        return 2;
    } else {
        func_80187B4C(&sp1F);
    }
    func_80187D04();
    if ((sp1F & 0xFF) == 8 || (sp1F & 0xFF) == 0x48 || (sp1F & 8) == 8) {
        return 0;
    } else {
        return -1;
    }
}

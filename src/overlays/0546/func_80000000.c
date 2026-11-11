#include "types.h"
#include "m2c_compat.h"

s32 func_80000000(u8 *arg0) {
    switch ((M2C_FIELD(arg0, u16 *, 0x496))) {
        case 0xD5E:
            return 0xD5F;
        case 0xD5F:
            return 0xD60;
        case 0xD60:
            return 0xD61;
        case 0xD62:
            return 0xD63;
        case 0xD64:
            return 0xD65;
        case 0xD66:
            return 0xD67;
        case 0xD67:
            return 0xD68;
        case 0xD68:
            return 0xD69;
        case 0xD6A:
            return 0xD6B;
        case 0xD6B:
            return 0xD6C;
        case 0xD6C:
            return 0xD6D;
        case 0xD6E:
            return 0xD6F;
        case 0xD70:
            return 0xD71;
        case 0xD71:
            return 0xD72;
        case 0xD73:
            return 0xD74;
        case 0xD74:
            return 0xD75;
        case 0xD89:
            return 0xD8A;
        default:
            return 0;
    }
}

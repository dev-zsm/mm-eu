#include "types.h"

// jump table jtbl_80C01050 (cases 3..15) is not in the overlay's own sections; case value of the 'sw zero' unknown
s32 func_80000298(s32 a, s32 b, s32 *c, s32 d) {
    switch (b) {
        case 3:
            *c = 0;
            break;
    }
    return 0;
}

#include "types.h"

extern u8 D_801D11D8[];

u8 AudioOcarina_MapPitchToButton(u8 arg0) {
    u8 button = D_801D11D8[arg0 & 0x3F];

    if (button == 5) {
        if (arg0 & 0x80) {
            return 2;
        }
        return 3;
    }
    return button;
}

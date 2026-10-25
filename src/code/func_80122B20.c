#include "types.h"

typedef struct {
    s32 enabled;
    s32 counter;
} FrameAdvance;

typedef struct {
    u16 cur;
    u8 pad2[0xA];
    u16 press;
} Input;

// True when every bit of mask is set; written this way because the ROM computes it with a nor.
#define BTN_ALL(value, mask) (~((value) | ~(mask)) == 0)

s32 FrameAdvance_Update(FrameAdvance *frameAdvance, Input *input) {
    if (frameAdvance->enabled == 0 ||
        (BTN_ALL(input->cur, 0x2000) &&
         (BTN_ALL(input->press, 0x10) ||
          (BTN_ALL(input->cur, 0x10) && ++frameAdvance->counter >= 9)))) {
        frameAdvance->counter = 0;
        return 1;
    }
    return 0;
}

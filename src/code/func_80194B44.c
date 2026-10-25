// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad[0x7988];
    void *queue;
} AudioState;
extern AudioState D_801F84B0;
extern s32 func_80088070(void *queue, void *msg, s32 flags);
void AudioThread_WaitForAudioResetQueueP(void) {
    s32 neg;
    s32 msg;
    do {
        neg = -1;
    }
    while (func_80088070(((AudioState *) (&D_801F84B0))->queue, &msg, 0) != neg);
}

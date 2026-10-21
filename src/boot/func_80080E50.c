// FLAGS: -O2 -g0
#include "types.h"

extern u8 D_8009B690[];
void func_80087CB0(void *a, u32 b, u32 c);

// Sends a NULL message to queue D_8009B690, the queue drained by func_80080BD4.
// Likely osSendMesg with OS_MESG_BLOCK (libultra).
void func_80080E50(void) {
    func_80087CB0(D_8009B690, 0, 1);
}

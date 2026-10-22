// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

typedef struct BootCtx {
    u8 pad0[0x7DC];
    void *head;
} BootCtx;

extern BootCtx *D_8009C220;
extern u8 D_800987FC[];
extern s32 osSetIntMask(s32 a0, void *a1, void *a2, void **a3);
extern void func_8008198C(void *a0, void *a1, void *a2);

void Fault_RemoveAddrConvClient(void *arg0, void *unused) {
    void *prev;
    void *cur;
    s32 flag;
    s32 saved;

    flag = 0;
    prev = 0;
    cur = D_8009C220->head;
    saved = osSetIntMask(1, unused, arg0, 0);
    if (cur != 0) {
        do {
            if (cur == arg0) {
                if (prev != 0) {
                    *(void **)prev = *(void **)arg0;
                } else {
                    D_8009C220->head = arg0;
                    if (D_8009C220->head != 0) {
                        D_8009C220->head = *(void **)arg0;
                    } else {
                        flag = 1;
                    }
                }
                break;
            }
            prev = cur;
            cur = *(void **)cur;
        } while (cur != 0);
    }
    osSetIntMask(saved, prev, arg0, (void **)&D_8009C220);
    if (flag != 0) {
        func_8008198C(D_800987FC, arg0, arg0);
    }
}

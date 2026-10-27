// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_8009C220;

typedef struct BootEntry {
    struct BootEntry *next;
    s32 (*fn)(s32, void *);
    void *data;
} BootEntry;

s32 Fault_ConvertAddress(s32 arg0) {
    BootEntry *e = *(BootEntry **)(D_8009C220 + 0x7DC);
    s32 ret;

    while (e != 0) {
        if (e->fn != 0) {
            ret = e->fn(arg0, e->data);
            if (ret != 0) {
                return ret;
            }
        }
        e = e->next;
    }
    return 0;
}

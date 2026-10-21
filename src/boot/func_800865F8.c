// FLAGS: -O2 -g0
#include "types.h"

typedef struct Entry {
    s32 next;
    void (*fn)(void);
} Entry;

extern s32 D_800976A0;

void func_800865F8(void) {
    Entry *s0;
    Entry *s1;
    s32 off;
    void (*fn)(void);

    off = D_800976A0;
    s0 = (Entry *)&D_800976A0;
    s1 = 0;
    while (off != 0) {
        s0 = (Entry *)((u8 *)s0 + off);
        fn = s0->fn;
        if (fn != 0) {
            fn();
        }
        off = s0->next;
        s0->next = (s32)s1;
        s1 = s0;
    }
    D_800976A0 = (s32)s1;
}

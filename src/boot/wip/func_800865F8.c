// FLAGS: -O2 -g0
#include "types.h"

typedef struct Entry {
    s32 next;
    void (*fn)(void);
} Entry;

extern s32 D_800976A0;

/* shortcut: 12/28 instr differ, prologue order and loop back-edge (bnel) not reproduced, revisit with more sweeps */
void func_800865F8(void) {
    Entry *s0;
    Entry *s1;
    s32 next;
    s32 head;

    head = D_800976A0;
    s0 = (Entry *)&D_800976A0;
    s1 = 0;
    if (head != 0) {
        s0 = (Entry *)((u8 *)s0 + head);
        do {
            if (s0->fn != 0) {
                s0->fn();
            }
            next = s0->next;
            s0->next = (s32)s1;
            s1 = s0;
            s0 = (Entry *)((u8 *)s0 + next);
        } while (next != 0);
    }
    D_800976A0 = (s32)s1;
}

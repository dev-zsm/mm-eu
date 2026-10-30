#ifndef STACKCHECK_H
#define STACKCHECK_H

#include "types.h"

/* One monitored stack: the stack area is filled with initValue when the entry is registered. */
typedef struct StackEntry {
    /* 0x00 */ struct StackEntry *next;
    /* 0x04 */ struct StackEntry *prev;
    /* 0x08 */ u32 *head;      /* lowest address of the stack area */
    /* 0x0C */ u32 *tail;      /* end of the stack area */
    /* 0x10 */ u32 initValue;
    /* 0x14 */ s32 minSpace;   /* -1: the free space is not checked */
    /* 0x18 */ const char *name;
} StackEntry;

extern StackEntry *D_80096DE0;  /* first entry of the list */
extern StackEntry *D_80096DE4;  /* last entry of the list */

void StackCheck_Init(StackEntry *entry, void *stackBottom, void *stackTop, u32 initValue, s32 minSpace, const char *name);
void StackCheck_Cleanup(StackEntry *entry);
s32 StackCheck_GetState(StackEntry *entry);
s32 StackCheck_CheckAll(void);
s32 StackCheck_Check(StackEntry *entry);

#endif

#ifndef DBG_H
#define DBG_H

#include "types.h"

/* Fault screen entry points used by the boot modules; the Fault module itself owns them. */
void Fault_AddHungupAndCrash(const char *file, s32 line);
void Fault_AddHungupAndCrashImpl(const char *exp1, const char *exp2);

void _dbg_hungup(const char *file, s32 line);

#endif

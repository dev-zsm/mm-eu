#include "types.h"
#include "generated/code_funcs.h"

typedef struct DbgObj {
    u8 pad0[0x24];
    s16 type;
    u8 pad26[2];
    struct DbgObj* next;
} DbgObj;

typedef struct {
    s16 funcIdx;
    void* arg;
} DbgEntry;

typedef void (*DbgDrawFunc)(DbgObj*, void*, s32);

extern DbgDrawFunc D_801BBB40[];
extern DbgEntry D_801BBB48[];
extern DbgObj* D_801EB7F0;

void DebugDisplay_DrawObjects(struct PlayState *play) {
    DbgObj* obj;
    DbgEntry* entry;

    for (obj = D_801EB7F0; obj != NULL; obj = obj->next) {
        entry = &D_801BBB48[obj->type];
        D_801BBB40[entry->funcIdx](obj, entry->arg, play);
    }
}

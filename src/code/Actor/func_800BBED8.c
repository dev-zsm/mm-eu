#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} CategoryEntry;

typedef struct {
    u8 pad0[0x18];
    CategoryEntry entries[1];
} CategoryTable;

typedef struct {
    u8 pad0[2];
    u8 category;
} CategoryActor;

void Actor_ChangeCategory(s32 arg0, CategoryTable *table, CategoryActor *actor, u8 category) {
    table->entries[actor->category].unk0 = 1;
    actor->category = category;
}

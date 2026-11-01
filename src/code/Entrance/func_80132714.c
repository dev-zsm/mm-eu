#include "types.h"

typedef struct {
    s8 unk0;
    s8 unk1;
} EntranceEntry;

EntranceEntry *Entrance_GetTableEntry(u16 entrance);

s8 Entrance_GetSpawnNum(u16 entrance) {
    return Entrance_GetTableEntry(entrance)->unk1;
}

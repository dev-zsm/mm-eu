#include "types.h"

typedef struct {
    u8 attack[0x20];
} DamageTable;

void DamageTable_Clear(DamageTable *table) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        table->attack[i] = 0;
    }
}

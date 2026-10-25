#include "types.h"

typedef struct {
    u8 pad0[0x44];
    u8 owlId;
    u8 pad45;
    u16 owlFlags;
} SaveContext;
extern SaveContext D_801E6EF0;
extern struct {
    u16 flag;
    u16 pad;
} D_801C29F2[];
void Sram_ActivateOwl(u8 owlId) {
    u16 new_var;
    new_var = D_801E6EF0.owlFlags; D_801E6EF0.owlFlags = D_801C29F2[owlId ^ 0].flag | new_var; if (D_801E6EF0.owlId == 0xFF) {
        D_801E6EF0.owlId = owlId;
    }
}

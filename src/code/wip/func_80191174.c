#include "types.h"

extern void *D_801FAD00;
extern void *D_801FAD04;
extern void *D_801FAD08;

void *AudioLoad_GetLoadTable(s32 index) {
    void *table;

    switch (index) {
        case 0:
            return D_801FAD00;
        case 1:
            return D_801FAD04;
        case 2:
            table = D_801FAD08;
            return table;
    }
    return 0;
}

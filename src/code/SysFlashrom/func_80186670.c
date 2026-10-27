#include "types.h"

extern u32 D_801F3670;
extern char D_801D7AC0[], D_801D7AC8[], D_801D7ACC[], D_801D7AD0[], D_801D7AD8[], D_801D7AE0[];

char *SysFlashrom_GetVendorStr(void) {
    switch (D_801F3670) {
        case 0xC20000:
            return D_801D7AC0;
        case 0xC20001:
            return D_801D7AC8;
        case 0xC2001E:
            return D_801D7ACC;
        case 0x3200F1:
            return D_801D7AD0;
        case 0xC2001D:
            return D_801D7AD8;
        default:
            return D_801D7AE0;
    }
}

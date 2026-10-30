// FLAGS: -O2 -g3
#include "dbg.h"
#include "yaz0.h"

extern char D_800984B0[];  /* "slidma slidstart_szs ret=%d" */
extern char D_800984CC[];  /* "src:%08lx dst:%08lx siz:%08lx" */

void Yaz0_Decompress(u32 romStart, void *dst, u32 size) {
    s32 status;
    char msg1[0x54];
    char msg2[0x50];

    if (D_8009C1E8 != NULL) {
        while (D_8009C1E8 != NULL) {
            usleep(0xA);
        }
    }
    D_8009C1E8 = D_8009BDE8 + YAZ0_BUFFER_SIZE;
    D_8009C1EC = romStart;
    D_8009C1F0 = size;
    status = Yaz0_DecompressImpl(Yaz0_FirstDMA(), dst);
    if (status != 0) {
        sprintf(msg1, D_800984B0, status);
        sprintf(msg2, D_800984CC, romStart, dst, size);
        Fault_AddHungupAndCrashImpl(msg1, msg2);
    }
    D_8009C1E8 = NULL;
}

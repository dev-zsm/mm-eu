// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 id;
    u8 pad[7];
} Ent;

extern void AudioOcarina_Start(a0);
extern s8 D_801D0E5C;
extern u8 D_801F4CAC;
extern Ent D_801CF974[][20];
extern u16 D_801F4CB0[];

// matching: old-style parameters leave the forwarded a0 unspilled
void AudioOcarina_StartForSongCheck(a0, a1)
    s32 a0;
    u8 a1;
{
    u8 i;
    u8 n;

    AudioOcarina_Start(a0);
    D_801D0E5C = 8;
    D_801F4CAC = a1;

    for (i = 0; i < 0x15; i++) {
        n = 0;
        if (a1 > 0) {
            do {
                if (D_801CF974[i][D_801F4CB0[i]].id != 0xFF) {
                    n++;
                }
                D_801F4CB0[i]++;
            } while (n < a1);
        }
        if (D_801CF974[i][D_801F4CB0[i]].id == 0xFF) {
            D_801F4CB0[i]++;
        }
    }
}

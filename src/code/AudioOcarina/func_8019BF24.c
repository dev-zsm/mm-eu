// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 buttonIdx; u8 pad[7]; } SongPitch;
typedef struct { u8 len; u8 buttons[8]; } SongButtons;

extern SongPitch D_801CF974[][20];
extern u8 D_801D11D8[];
extern SongButtons D_801D1378[];

void AudioOcarina_MapSongFromPitchToButton(u8 songIndex, u8 dst, u8 len) {
    u8 j = 0;
    u8 i = 0;
    u8 b;

    if (len > 0) {
        do {
            b = D_801CF974[songIndex][i].buttonIdx;
            i++;
            if (b != 0xFF) {
                D_801D1378[dst].buttons[j] = D_801D11D8[b];
                j++;
            }
        } while (j < len && i < 0x10);
    }
    D_801D1378[dst].len = len;
}

#include "types.h"

typedef struct {
    u8 pad0[8];
    u8 *roomShape;
    u32 segment;
} Room;

typedef void (*RoomDrawFunc)(void *play, Room *room, u32 flags);

extern u32 D_801EFA0C;
extern RoomDrawFunc D_801C29DC[];

void Room_Draw(void *play, Room *room, u32 flags) {
    if (room->segment != 0) {
        D_801EFA0C = room->segment + 0x80000000;
        D_801C29DC[*room->roomShape](play, room, flags);
    }
}

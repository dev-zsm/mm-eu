#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 type;
} RoomShape;

typedef struct {
    u8 pad0[8];
    RoomShape *unk8;
} Room;

extern u8 D_801D603C[];

extern void Room_DrawImageSingle(void *play, Room *room);
extern void Room_DrawImageMulti(void *play, Room *room);
extern void func_800862F0(u8 *msg, s32 line);

void Room_DrawImage(void *play, Room *room) {
    RoomShape *shape = room->unk8;

    if (shape->type == 1) {
        Room_DrawImageSingle(play, room);
    } else if (shape->type == 2) {
        Room_DrawImageMulti(play, room);
    } else {
        func_800862F0(D_801D603C, 0x3C5);
    }
}

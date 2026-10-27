#include "types.h"

typedef struct {
    u32 word[2];
} SurfaceType;

typedef struct {
    u8 pad0[0x1C];
    SurfaceType *unk1C;
} CollisionHeader;

CollisionHeader *BgCheck_GetCollisionHeader(void *arg0, s32 arg1);

u32 SurfaceType_GetData(void *arg0, u16 *arg1, s32 arg2, s32 arg3) {
    CollisionHeader *header = BgCheck_GetCollisionHeader(arg0, arg2);
    SurfaceType *data;

    if (header == NULL || arg1 == NULL) {
        return 0;
    }
    data = header->unk1C;
    if (data == NULL) {
        return 0;
    }
    return data[*arg1].word[arg3];
}

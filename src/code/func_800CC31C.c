#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;

extern void Camera_GetFloorYNorm(void *camera, void *floorPoly, V3 *pos, s32 *bgId);

void Camera_GetFloorY(void *camera, V3 *pos) {
    V3 checkPos;
    s32 pad[2]; // Unused, only here to make the stack frame match.
    void *floorPoly;
    s32 bgId;

    checkPos = *pos;
    checkPos.y += 80.0f;
    Camera_GetFloorYNorm(camera, &floorPoly, &checkPos, &bgId);
}

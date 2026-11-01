#include "types.h"

typedef struct {
    u8 pad0[0x8C];
    u8 *play;
} Cam;
extern s32 BgCheck_CameraLineTest1(void *colCtx, void *pos, s32 a2, void *out, void *poly, s32 a5, s32 a6, s32 a7, s32 a8, void *bgId);
extern f32 CollisionPoly_GetPointDistanceFromPlane(void *poly, void *pos);
s32 Camera_CheckOOB(Cam *camera, void *pos, s32 a2) {
    s32 pad2;
    u8 out[12];
    s32 pad;
    s32 bgId;
    void *poly;
    u8 *new_var;
    new_var = camera->play + 0x830;
    poly = (void *) 0;
    if (BgCheck_CameraLineTest1(new_var, pos, a2, out, &poly, 1, 1, 1, 0, &bgId)) {
        if (CollisionPoly_GetPointDistanceFromPlane(poly, pos) < 0.0f) {
            return 1; } }
    return 0;
}

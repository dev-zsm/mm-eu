#include "types.h"

typedef struct {
    s8 dir[3];
    u8 color[3];
} DirectionalParams;

typedef struct {
    u8 color[3];
    u8 pad3;
    u8 colorCopy[3];
    u8 pad7;
    s8 dir[3];
} DirectionalNode;

extern DirectionalNode *Lights_FindSlot(void *lights);

void Lights_BindDirectional(void *lights, DirectionalParams *params, s32 unused) {
    DirectionalNode *node = Lights_FindSlot(lights);

    if (node != NULL) {
        node->colorCopy[0] = node->color[0] = params->color[0];
        node->colorCopy[1] = node->color[1] = params->color[1];
        node->colorCopy[2] = node->color[2] = params->color[2];
        node->dir[0] = params->dir[0];
        node->dir[1] = params->dir[1];
        node->dir[2] = params->dir[2];
        node->pad3 = 0;
    }
}

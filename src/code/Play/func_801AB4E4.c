#include "types.h"

typedef struct {
    u8 pad0[0x17000];
    u16 value;
} State;
extern void Environment_FadeInGameOverLights(void);
void func_801AB4E4(State *state) {
    u16 *new_var;
    new_var = &state->value;
    if ((((*new_var) >= 2) && ((*new_var) < 20)) || (((*new_var) > 20) && ((*new_var) < 24))) {
        Environment_FadeInGameOverLights();
    }
}

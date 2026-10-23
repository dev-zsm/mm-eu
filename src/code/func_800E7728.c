// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 CollisionCheck_ApplyDamage();
s32 CollisionCheck_ApplyDamageSphere(s32 a0, s32 a1, s32 a2) { return CollisionCheck_ApplyDamage(a0, a1, a2, a2 + 0x18); }

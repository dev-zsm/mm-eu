// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void CollisionCheck_ApplyDamage();
void CollisionCheck_ApplyDamageCyl(s32 a0, s32 a1, s32 a2) { CollisionCheck_ApplyDamage(a0, a1, a2, a2 + 0x18); }

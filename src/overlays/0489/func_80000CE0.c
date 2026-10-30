#include "types.h"

typedef struct { u8 pad0[0x308]; s8 unk308; s8 unk309; s8 unk30A; } A;

void func_80000CE0(A *a) {
 a->unk309 += a->unk30A;
 if (a->unk309 >= a->unk308) {
  a->unk309 = 0;
 } else if (a->unk309 < 0) {
  a->unk309 = a->unk308 - 1;
 }
}

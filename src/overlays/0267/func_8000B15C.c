typedef struct { char pad[0x1C]; short unk1C; } A;
int func_8000B15C(int a, int b, int *c, int d, int e, A *f) {
  if (f->unk1C == 0xCA && b != 0x12 && b != 0x13) { *c = 0; }
  return 0;
}

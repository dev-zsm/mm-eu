typedef struct { char pad[0x1C]; short unk1C; } A;
void func_800E09D8();
void func_80000448(A *a, int g) { if (a->unk1C != 1) { func_800E09D8(g, (char *)a + 0x358); } }

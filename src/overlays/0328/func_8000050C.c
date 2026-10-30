typedef struct { char pad[0xD78]; unsigned char *unkD78; } A;
extern void (*D_80A263EC[])();
void func_8000050C(A *a) { D_80A263EC[*a->unkD78](); }

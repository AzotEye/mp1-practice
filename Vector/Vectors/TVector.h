#ifndef FUNC

#define FUNC

typedef struct {
    int n;
    double* x;
}Tvect;

void allo(Tvect* v, int n);
Tvect summ(Tvect* v1, Tvect* v2);
Tvect subb(Tvect* v1, Tvect* v2);
double mult(Tvect* v1, Tvect* v2);
void fill(Tvect* v);
void print(Tvect* v);

#endif
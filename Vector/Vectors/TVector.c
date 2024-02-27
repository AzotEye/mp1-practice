#include "TVector.h"
#include <stdlib.h>


void allo(Tvect* v, int n)
{
    v->n = n;
    v->x = (double*)malloc(sizeof(double) * n);
}
Tvect summ(Tvect* v1, Tvect* v2)
{
    Tvect sum;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("error");
        sum.x = NULL;
        sum.n = 0;
        return sum;
    }
    allo(&sum, v1->n);
    for (i = 0; i < sum.n; i++)
    {
        sum.x[i] = v1->x[i] + v2->x[i];
    }
    return sum;
}
void fill(Tvect* v)
{
    int i = 0;
    printf("Cords = ");
    for (i = 0; i < v->n; i++)
    {
        scanf("%lf", &(v->x[i]));
    }
}
void print(Tvect* v)
{
    int i = 0;
    for (i = 0; i < v->n; i++)
    {
        printf("%lf ", v->x[i]);
    }
    printf("\n");
}
Tvect subb(Tvect* v1, Tvect* v2)
{
    Tvect sub;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("error");
        sub.x = NULL;
        sub.n = 0;
        return sub;
    }
    allo(&sub, v1->n);
    for (i = 0; i < sub.n; i++)
    {
        sub.x[i] = v1->x[i] - v2->x[i];
    }
    return sub;
}
double mult(Tvect* v1, Tvect* v2)
{
    double mult = 0;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("error");
        mult = 0;
        return mult;
    }
    for (i = 0; i < v1->n; i++)
    {
        mult += v1->x[i] * v2->x[i];
    }
    return mult;
}
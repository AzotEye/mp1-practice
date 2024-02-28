#include <stdio.h>
#include <stdlib.h>
#include "TVector.h"




void main()
{
    int n1, n2;
    double multt = 0;
    Tvect v1, v2, s1, s2;
    fill("vect1.txt",&v1);
    fill("vect2.txt",&v2);
    s1 = summ(&v1, &v2);
    s2 = subb(&v1, &v2);
    multt = mult(&v1, &v2);
    write("summ.txt", &s1);
    write("subb.txt", &s2);
    write("mult.txt", &multt);
    free(v1.x);
    free(v2.x);
    if (s1.x != NULL)
    {
        free(s1.x);
    }
    if (s2.x != NULL)
    {
        free(s2.x);
    }
    return;
}


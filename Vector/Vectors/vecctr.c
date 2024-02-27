#include <stdio.h>
#include <stdlib.h>
#include "TVector.h"




void main()
{
    int n1, n2;
    double multt = 0;
    Tvect v1, v2, s1, s2;
    printf("Dim of v1 = ");
    scanf("%d", &n1);
    allo(&v1, n1);
    printf("Dim of v2 = ");
    scanf("%d", &n2);
    allo(&v2, n2);
    fill(&v1);
    fill(&v2);
    s1 = summ(&v1, &v2);
    printf("Sum = ");
    print(&s1);
    s2 = subb(&v1, &v2);
    printf("Sub = ");
    print(&s2);
    multt = mult(&v1, &v2);
    printf("Mult = %lf", multt);
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


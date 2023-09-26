#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, r1, x2, y2, r2;
    printf("Input the coordinates of the center of the first circle and its radius: ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Input the coordinates of the center of the second circle and its radius: ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if ((r1 > 0) && (r2 > 0))
    {
        if ((x1 == x2) && (y1 == y2))
        {
            if (r1 == r2)
            {
                printf("The circles coincide");//совпадают
            }
            else
            {
                printf("One of the circles lies inside the other");//один внутри другого
            }
        }
        else
        {
            double distance, R, r;
            if (r1 > r2)
            {
                R = r1;
                r = r2;
            }
            else
            {
                R = r2;
                r = r1;//выбрали больший и меньший радиусы
            }
            distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));//расстояние между центрами
            if (distance == r1 + r2)
            {
                printf("Circles touch at one point outside");//внешнее касание
            }
            else if (distance > r1 + r2)
            {
                printf("Circles do not intersect");//не пересекаются
            }
            else if ((distance < r1 + r2) && (distance > R - r))
            {
                printf("Circles intersect in two points");// пересекаются в двух точках
            }
            else if (distance < R - r)
            {
                printf("One of the circles lies inside the other");//один внутри другого
            }
            else if (distance == R - r)
            {
                printf("Circles touch at one point inside");//внутреннее касание
            }

        }
    }
    else
    {
        printf("Incorrect data!"); // проверка на положительный радиус
    }
    return 0;
}
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
                printf("The circles coincide");//sovpadayt
            }
            else
            {
                printf("One of the circles lies inside the other");//odin vnutry drugogo
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
                r = r1;//vybrali max i min radiusy
            }
            distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));//rasstoyanie mezhdy centrami
            if (distance == r1 + r2)
            {
                printf("Circles touch at one point outside");//vnechnee kasanie
            }
            else if (distance > r1 + r2)
            {
                printf("Circles do not intersect");//ne peresecautca
            }
            else if ((distance < r1 + r2) && (distance > R - r))
            {
                printf("Circles intersect in two points");//peresecautca v dvyh tochkah
            }
            else if (distance < R - r)
            {
                printf("One of the circles lies inside the other");//pdin vnytry drygogo
            }
            else if (distance == R - r)
            {
                printf("Circles touch at one point inside");//kasanie vnutri
            }

        }
    }
    else
    {
        printf("Incorrect data!"); //proverca na polozhitelny radius
    }
    return 0;
}
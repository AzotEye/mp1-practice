#include <stdio.h>
int main()
{
    double h, w, d;
    printf("Input height, width, depth of the wardrobe in cm: ");
    scanf("%lf %lf %lf", &h, &w, &d);
    while ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
    {
        printf("Incorrect! Try again please! Input height, width, depth of the wardrobe in cm: ");
        scanf("%lf %lf %lf", &h, &w, &d);
    }
    return 0;
}
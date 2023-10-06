#include <stdio.h>
int main()
{
    double h, w, d, m1, m2, m3, m4, m5, colvopolk, m;
    printf("Input height, width, depth of the wardrobe in cm: ");
    scanf("%lf %lf %lf", &h, &w, &d);
    while ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
    {
        printf("Incorrect! Try again please! Input height, width, depth of the wardrobe in cm: ");
        scanf("%lf %lf %lf", &h, &w, &d);
    }
    if (h < 190)
    {
        colvopolk = 4;
    }
    else
    {
        colvopolk = 5;
    }
    m1 = h * w * 0.5 * 0.8;
    m2 = 2 * h * d * 1.5 * 0.5;
    m3 = 2 * w * d * 1.5 * 0.5;
    m4 = h * h * w * 0.7;
    m5 = colvopolk * w * d * 1.5 * 0.5;
    m = (m1 + m2 + m3 + m4 + m5) / 1000;
    printf("Weight of your wardrode in kg: %lf", m);
    return 0;
}
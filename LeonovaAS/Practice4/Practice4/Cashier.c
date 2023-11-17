#include <stdio.h>
#define name = ["Loaf", "Sliced bread", "Baguette", "Croissant with chocolate", "Croissant with almonds", "Croissant with vanilla cream", "Apple ans Cinnamon Pie", "Pumpkin Spice Pie", "Latte", "Cappuccino"]
#define price = [59, 59, 79, 89, 119, 89, 359, 399, 69, 69]
#define barcode = [[2,0,4,5], [2, 0, 4, 6], [2, 0, 4, 7], [0, 1, 1, 1], [0, 1, 1, 2], [0, 1, 1, 3], [6, 9, 9, 3], [6, 9, 9, 4], [8, 0, 0, 1], [8, 0, 0, 2]]

int main() 
{
    int i, j, a[4], k;
    printf("Input the barcode, please: \n");
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i] == 0)
                printf("ok");
        }
    }
    return 0;
}
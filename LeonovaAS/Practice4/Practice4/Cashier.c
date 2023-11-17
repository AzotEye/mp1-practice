#include <stdio.h>
#define barcode = [[1, 1, 1, 2], [2, 2, 2, 3], [0, 0, 9, 0], [1, 2, 3, 4], [0, 1, 1, 2], [0, 1, 1, 3], [6, 9, 9, 3], [6, 9, 9, 4], [8, 0, 0, 1], [8, 0, 0, 2]];


int main() 
{
    int a[4], i;
    printf("Input the barcode, please: \n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
    }
  
    return 0;
}


//name["Loaf", "Sliced bread", "Baguette", "Croissant with chocolate", "Croissant with almonds", "Croissant with vanilla cream", "Apple ans Cinnamon Pie", "Pumpkin Spice Pie", "Latte", "Cappuccino"];;;; int code1[4] = [2, 0, 4, 5], code2[4] = [2, 0, 4, 6], code3[2, 0, 4, 7], code4[0, 1, 1, 1];
//int a[4], i, barcode[code1, code2, [0, 1, 1, 2], [0, 1, 1, 3], [6, 9, 9, 3], [6, 9, 9, 4], [8, 0, 0, 1], [8, 0, 0, 2]], price[59, 59, 79, 89, 119, 89, 359, 399, 69, 69];

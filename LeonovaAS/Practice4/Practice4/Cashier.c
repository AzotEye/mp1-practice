#include <stdio.h>


int is_same(int *a, int *b);
int the_flag(int* a1, int* a2, int* a3, int* a4, int* a5, int* a6, int* a7, int* a8, int* a9, int* a10, int* b);
void return_name(int check, char* a1, char* a2, char* a3, char* a4, char* a5, char* a6, char* a7, char* a8, char* a9, char* a10);




int main() 
{
    int a[4], i, flag, colvo = 0;
    float total_disk = 0, total_price = 0;
    int cod1[] = { 1, 0, 0, 0 }, cod2[] = { 1, 0, 0, 1 }, cod3[] = { 1, 0, 0, 2 }, cod4[] = {1, 0, 0, 3}, cod5[] = {1, 0, 0, 4}, cod6[] = {1, 0, 0, 5}, cod7[] = {1, 0, 0, 6}, cod8[] = {1, 0, 0, 7}, cod9[] = {1, 0, 0,  8}, cod10[] = {1, 0, 0, 9};
    char name1[] = { 'B', 'r', 'e', 'a', 'd' }, name2[] = { 'M', 'i', 'l', 'k' }, name3[] = { 'C', 'a', 'n', 'd', 'y' }, name4[] = { 'P', 'o', 't', 'a', 't', 'o' }, name5[] = { 'A', 'p', 'p', 'l', 'e' }, name6[] = { 'J', 'u', 'i', 'c', 'e' }, name7[] = { 'O', 'r', 'a', 'n', 'g', 'e' }, name8[] = { 'C', 'a', 'r', 'r', 'o', 't' }, name9[] = { 'C', 'o', 'o', 'k', 'i', 'e' }, name10[] = { 'T', 'o', 'm', 'a', 't', 'o'};
    int discount[] = { 0, 5, 15, 3, 5, 45, 0, 5, 37, 3 }, price[] = { 41, 69, 59, 14, 20, 119, 58, 9, 79, 25};
    int check[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

   
    do 
    {
        printf("How many products do you want to buy: ");
        scanf("%d", &colvo);

    } while (colvo <= 0); 

    do 
    {
        colvo--;
        printf("\nInput the barcode, please: \n");

        for (i = 0; i < 4; i++)
        {
            scanf("%d", &a[i]);
        }

        flag = the_flag(&(cod1[0]), &(cod2[0]), &(cod3[0]), &(cod4[0]), &(cod5[0]), &(cod6[0]), &(cod7[0]), &(cod8[0]), &(cod9[0]), &(cod10[0]), &(a[0]));
        
        switch (flag)
        {
        case 0:
        {
            printf("The barcode you input does not exist! Restart...");
            return 0;
        }
        case 1:
        {
            check[0]++;
            break;
        }
        case 2:
        {
            check[1]++;
            break;
        }
        case 3:
        {
            check[2]++;
            break;
        }
        case 4:
        {
            check[3]++;
            break;
        }
        case 5:
        {
            check[4]++;
            break;
        }
        case 6:
        {
            check[5]++;
            break;
        }
        case 7:
        {
            check[6]++;
            break;
        }
        case 8:
        {
            check[7]++;
            break;
        }
        case 9:
        {
            check[8]++;
            break;
        }
        case 10:
        {
            check[9]++;
            break;
        }

        }

    }while (colvo > 0);
    
    for (i = 0; i < 10; i++)
    {
        if (check[i] != 0)
        {
            printf("Name: ");
            return_name(i + 1, &(name1[0]), &(name2[0]), &(name3[0]), &(name4[0]), &(name5[0]), &(name6[0]), &(name7[0]), &(name8[0]), &(name9[0]), &(name10[0]));
            printf("\nPrice: %d. \nDiscount: %d. \nQuantity: %d. \nTotal price: %f\n", price[i], discount[i], check[i], price[i] * ((100 - discount[i]) * 0.01) * check[i]); 
            total_disk += price[i] * (discount[i] * 0.01) * check[i];
            total_price += price[i] * ((100 - discount[i]) * 0.01) * check[i];
        }
    }

    printf("\nYour total discount: %f\nYour total price: %f", total_disk, total_price);
    
  
    return 0;
}

int is_same(int *a, int *b)
{
    int i, k = 0;
    for (i = 0; i < 4; i++)
    {
        
        if (a[i] == b[i])
        {
            k += 1;
        }
        
    }
    if (k == 4)
    {
        return 1;
    }

    return 0;
}

int the_flag(int* a1, int* a2, int* a3, int* a4, int* a5, int* a6, int* a7, int* a8, int* a9, int* a10, int* b)
{
    int flag = 0;
    if (is_same(&(a1[0]), &(b[0])) == 1)
    {
        flag = 1;
    }
    if (is_same(&(a2[0]), &(b[0])) == 1)
    {
        flag = 2;
    }
    if (is_same(&(a3[0]), &(b[0])) == 1)
    {
        flag = 3;
    }
    if (is_same(&(a4[0]), &(b[0])) == 1)
    {
        flag = 4;
    }
    if (is_same(&(a5[0]), &(b[0])) == 1)
    {
        flag = 5;
    }
    if (is_same(&(a6[0]), &(b[0])) == 1)
    {
        flag = 6;
    }
    if (is_same(&(a7[0]), &(b[0])) == 1)
    {
        flag = 7;
    }
    if (is_same(&(a8[0]), &(b[0])) == 1)
    {
        flag = 8;
    }
    if (is_same(&(a9[0]), &(b[0])) == 1)
    {
        flag = 9;
    }
    if (is_same(&(a10[0]), &(b[0])) == 1)
    {
        flag = 10;
    }
    return flag;

}

void return_name(int check, char* a1, char* a2, char* a3, char* a4, char* a5, char* a6, char* a7, char* a8, char* a9, char* a10)
{
    int i;
    switch (check)
    {
    case 0:
        return;

    case 1:
    {
        for (i = 0; i < 5; i++)
        {
            printf("%c", a1[i]);
        }
        return;

    }
    case 2:
    {
        for (i = 0; i < 4; i++)
        {
            printf("%c", a2[i]);
        }
        return;
    }
    case 3:
    {
        for (i = 0; i < 5; i++)
        {
            printf("%c", a3[i]);
        }
        return;
    }
    case 4:
    {
        for (i = 0; i < 6; i++)
        {
            printf("%c", a4[i]);
        }
        return;
    }
    case 5:
    {
        for (i = 0; i < 5; i++)
        {
            printf("%c", a5[i]);
        }
        return;
    }
    case 6:
    {
        for (i = 0; i < 5; i++)
        {
            printf("%c", a6[i]);
        }
        return;
    }
    case 7:
    {
        for (i = 0; i < 6; i++)
        {
            printf("%c", a7[i]);
        }
        return;
    }
    case 8:
    {
        for (i = 0; i < 6; i++)
        {
            printf("%c", a8[i]);
        }
        return;
    }
    case 9:
    {
        for (i = 0; i < 6; i++)
        {
            printf("%c", a9[i]);
        }
        return;
    }
    case 10:
    {
        for (i = 0; i < 6; i++)
        {
            printf("%c", a10[i]);
        }
        return;
    }
    }
    return;
}
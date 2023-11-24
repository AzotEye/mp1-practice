#include <stdio.h>
#include <string.h>


#define N_PRODUCTS 10
#define N_SYMBOLS 5


char* codes[N_PRODUCTS] = { "1000", "1001", "1002", "1003", "1004", "1005", "1006", "1007", "1008", "1009"};
char* names[N_PRODUCTS] = { "Bread", "Milk", "Candy", "Potato", "Apple", "Juice", "Orange", "Carrot", "Cookie", "Tomato"};
int discount[N_PRODUCTS] = { 0, 5, 15, 3, 5, 45, 0, 5, 37, 3 },
price[N_PRODUCTS] = { 41, 69, 59, 14, 20, 119, 58, 9, 79, 25 };
int check[N_PRODUCTS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


int get_product_idx(char* barcode);
void enter_barcodes();
void print_check();
void print_total_info();


int main() 
{
    int i;
    float total_disk = 0, total_price = 0;

    enter_barcodes();
    print_check();
    print_total_info();
  
    return 0;
}



int get_product_idx(char* barcode)
{
    int i = 0;
    for (; i < N_PRODUCTS; i++)
    {
        if (strcmp(barcode, codes[i]) == 0)
            return i;
    }
    return -1;
}

void enter_barcodes()
{
    int cont;
    do
    {
        int pidx;
        char barcode[N_SYMBOLS];
        printf("\nInput the barcode, please: \n");
        scanf("%s", barcode);
        printf("Continue?\n");
        scanf("%d", &cont);

        pidx = get_product_idx(barcode);
        if (pidx < 0)
        {
            printf("Incorrect barcode\n");
            continue;
        }

        check[pidx]++;


    } while (cont == 1);
    return;
}
void print_check()
{
    int i;
    for (i = 0; i < N_PRODUCTS; i++)
    {
        if (check[i] != 0)
        {
            printf("Name: %s\n", names[i]);
            printf("\tPrice: %d. \nDiscount: %d. \nQuantity: %d. \nTotal price: %f\n",
                price[i], discount[i], check[i], price[i] * ((100 - discount[i]) * 0.01) * check[i]);
           
        }
    }
    return;
}
void print_total_info()
{
    float total_disk = 0, total_price = 0;
    int i;
    for (i = 0; i < N_PRODUCTS; i++)
    {
        if (check[i] != 0)
        {
            total_disk += price[i] * (discount[i] * 0.01) * check[i];
            total_price += price[i] * ((100 - discount[i]) * 0.01) * check[i];
        }
    }
    printf("\nYour total discount: %f\nYour total price: %f", total_disk, total_price);
    return;
}
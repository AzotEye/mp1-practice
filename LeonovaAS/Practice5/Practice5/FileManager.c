#include <stdio.h>
#include <Windows.h>
#include <string.h>

int main()
{
    char metod[10], path[100];
    printf("Input path: ");
    scanf("%c", &path);
    printf("Input sorting method: ");
    scanf("%c", &metod);
    printf("%ch \n &c", path, metod);
    //три метода сортирвки, вставкими, пузырьком, слиянием
    return 0;
}
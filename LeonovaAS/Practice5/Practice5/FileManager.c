#include <stdio.h>
#include "dirent.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h> 
#include <inttypes.h>

void sort_bubble(double *a, int n);
void sort_choose(double *a, int n);
void sort_input(double *a, int n);
void sort_merge(double *a, int left, int right);
void sort_fast(double *a, int n);

void print(double *a, int n);
void merge(double *a, int left, int mid, int right);
void swap(double *a, double *b);

void get_sorted(double* a, int n);

char* charconv(const char* str1);
char* file_name(char* a, const char* b);
int64_t getFileSize(const char* file_name);

DIR* dir;
struct dirent* ent;

int main()
{
    int i = 0, kolvo_files;
    char path[255];
    char* names[255];
    double sizes[255];

    printf("Input path to the directory ");
    scanf("%s", &path);
    
    dir = opendir(path);
    while ((ent = readdir(dir)) != false)
    {
       
       names[i] = charconv(ent->d_name);
       int64_t file_size = getFileSize(file_name(path, ent->d_name));
       sizes[i] = (double)file_size;
       i++;   
    }

    kolvo_files = i;
    int flag = 1, j;
    do
    {
        printf("\nDo you want to sort the files? ");
        scanf("%d", &flag);
        if (flag == 1)
        {
            
            double copy_of_sizes[255];

            for (i = 0; i < kolvo_files; i++)
            {
                copy_of_sizes[i] = sizes[i];
            }
            get_sorted(copy_of_sizes, kolvo_files);
            printf("\nSorted:\n");
            for (i = 0; i < kolvo_files; i++)
            {
                for (j = 0; j < kolvo_files; j++)
                {
                    if ((copy_of_sizes[i] == sizes[j]) && (sizes[j] != -1))
                    {
                        printf("%s ..... %lf\n", names[j], sizes[j]);
                    }
                }
            }
            printf("\nUNsorted:\n");
            for (i = 0; i < kolvo_files; i++)
            {
                if (sizes[i] != -1)
                    printf("%s ..... %lf\n", names[i], sizes[i]);
            }
        }
    } while (flag == 1);
    

    closedir(dir);
    return 0;
}

int64_t getFileSize(const char* file_name) {
    int64_t _file_size = 0;
    FILE* fd = fopen(file_name, "rb");
    if (fd == NULL) {
        _file_size = -1;
    }
    else {
        while (getc(fd) != EOF)
            _file_size++;
        fclose(fd);
    }
    return _file_size;
}

char* file_name(char* a, const char* b)
{
    char* name = malloc((strlen(a) + strlen(b) + 2) * sizeof(char));
    if (name != NULL)
        {
            strcpy(name, a);
            strcat(name, "\\");
            strcat(name, b);
            return name;
        }
    return 0;
    
}

void get_sorted(double* a, int n)
{
    time_t start, finish;
    int d = -1;
    do
    {
        printf("How do you want your files to be sorted?\n1. Bubble sort\n2. Choose sort\n3. Input sort\n4. Merge sort\n5. Quick sort\n");
        scanf("%d", &d);
    } while ((d <= 0)  || (d >= 6));
    switch (d)
    {
    case 1:
        start = time(NULL);
        sort_bubble(a, n);
        finish = time(NULL);
        
        printf("\nTime of sorting: %lf\n", difftime(start, finish));
        break;
    case 2:
        start = time(NULL);
        sort_choose(a, n);
        finish = time(NULL);
        
        printf("\nTime of sorting: %lf\n", difftime(start, finish));
        break;
    case 3:
        start = time(NULL);
        sort_input(a, n);
        finish = time(NULL);
        
        printf("\nTime of sorting: %lf\n", difftime(start, finish));
        break;
    case 4:
        start = time(NULL);
        sort_merge(a, 0, n-1);
        finish = time(NULL);
        
        printf("\nTime of sorting: %lf\n", difftime(start, finish));
        break;
    case 5:
        start = time(NULL);
        sort_fast(a, n);
        finish = time(NULL);
        
        printf("\nTime of sorting: %lf\n", difftime(start, finish));
        break;
    }
}

void print(double* a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%lf ", a[i]);
    }
    printf("\n");
}

void swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

void sort_bubble(double* a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);

            }
        }
    }
    return;
}

void sort_choose(double* a, int n)
{
    int i, j;
    double min;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void sort_input(double* a, int n)
{
    int i, j;
    double min;
    for (i = 1; i < n; i++)
    {
        min = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > min)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = min;
    }
}

void merge(double* a, int left, int mid, int right) {

    int i1 = 0, i2 = 0, n;

    double* f = (double*)malloc(sizeof(double) * (mid - left + 1));
    double* s = (double*)malloc(sizeof(double) * (right - mid));


    for (i1 = 0; i1 < mid - left + 1; i1++)
    {
        f[i1] = a[left + i1];
    }

    for (i2 = 0; i2 < right - mid; i2++)
    {
        s[i2] = a[mid + 1 + i2];
    }

    i1 = 0;
    i2 = 0;
    n = left;

    while (i1 < mid - left + 1 && i2 < right - mid)
    {
        if (f[i1] <= s[i2])
        {
            a[n++] = f[i1++];
        }
        else
        {
            a[n++] = s[i2++];
        }

    }

    while (i1 < mid - left + 1)
    {
        a[n++] = f[i1++];
    }

    while (i2 < right - mid)
    {
        a[n++] = s[i2++];
    }

    free(f);
    free(s);
}

void sort_merge(double* a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    sort_merge(a, left, (left + right) / 2);
    sort_merge(a, (left + right) / 2 + 1, right);
    merge(a, left, (left + right) / 2, right);
}

void sort_fast(double* a, int n)
{
    int i = 0, j = n - 1;
    double pivot = a[(n - 1) / 2];
    while (i < j)
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    if (j > 0)
    {
        sort_fast(a, j);
    }
    if (i > n - 1)
    {
        sort_fast(&a[i], i);
    }
}

char* charconv(const char* a) 
{
    size_t b = strlen(a), c = b + 1;
    char* norm = malloc(c * sizeof(char));
    strcpy(norm, a);
    return norm;
}
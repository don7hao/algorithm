#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *dst, char *src)
{
    char tmp = *dst;
    *dst = *src;
    *src = tmp;

    return;
}

void quick_sort(char array[], int left, int right)
{

    int i, j;
    char pivot;

    if (left < right){
        i = left, j = right+1;
        pivot = array[left];
        while (i < j){
            while (pivot > array[++i]){
            }

            while (pivot < array[--j]){
            }

            if (i < j){
                swap(&array[i], &array[j]);
            }
        }

        swap(&array[left], &array[j]);
        quick_sort(array, left, j-1);
        quick_sort(array, j+1, right);
    }
    return;
}


int main(void)
{
    char array[] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};

    quick_sort(array, 0, sizeof(array)-1);
#if 1
    printf("quick sort : \n");
    int i = 0x00;
    for (; i < sizeof(array); i++)
        printf("%d ", array[i]);
    printf("\n");
#endif

    return;
}

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

int get_random(char A[], int left,int right)
{
    // 产生 left 和 right 之间的一个随机整数
    int result = left + rand()%(right - left + 1);
    swap(&A[result], &A[left]); /* 将pivot藏到左边 */
    return A[left]; /* 返回 pivot */
}

char get_median3(char A[], int left, int right )
{
    int center = (left + right)/2;
    if (A[left] > A[center])
        swap(&A[left], &A[center]);
    if (A[left] > A[right])
        swap( &A[left], &A[right]);
    if ( A[center] > A[right] )
        swap(&A[center], &A[right] );
    /* A[left] <= A[center] <= A[right] */
    swap(&A[center], &A[left]); /* 将pivot藏到左边 */
    return A[left]; /* 返回 pivot */
}

void quick_sort(char array[], int left, int right)
{

    int i, j;
    char pivot;

    if (left < right){
        i = left, j = right+1;
#if 1
        pivot = get_median3(array, left, right);//array[left];
#else
        pivot = get_random(array, left, right);
#endif
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

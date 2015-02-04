#include <stdio.h>
#include <stdlib.h>

void copy_array(char dst[], int low, int high, char src[])
{
    int i = 0x00, j = low;
    for(; j <= high; i++, j++){
        dst[j] = src[i];
    }
    return;
}

void merge(char array[], int low, int m, int high)
{
    int i = low, j = m+1;

    char *tmp_array = (char *)calloc(1, high);
    if (NULL == tmp_array){
        printf("calloc error!\n");
        return;
    }

    char *p = tmp_array;
    int idx = low;
    for (;idx <= high; idx++){
        if (i <= m && (j > high || array[i] < array[j])){
            *p++ = array[i++];
        }else{
            *p++ = array[j++];
        }
    }

    copy_array(array, low, high, tmp_array);

    free(tmp_array);
    tmp_array = NULL;
    return;
}


/* 自底向上归并 */
void merge_pass(char array[], int step, int length)
{
    int i = 0x00;
    int high = 0x00, middle = 0x00, low = 0x00;
    for (; i+2*step-1 < length; i += 2*step){
        high = i + 2*step - 1;
        middle = i + step - 1;
        low = i;
        /*printf("%d, %d, %u, %d\n", high, middle, low, array[i]);*/
        merge(array, low, middle, high);
    }
    if ((i+step-1) < length){
        high = length - 1;
        middle = i + step - 1;
        low = i;
        /*printf("--- %d, %d, %d, %d, %d----\n", i, high, middle, low, array[i]);*/
        merge(array, low, middle, high);
    }
    return;
}

/* 自顶向下归并 */
void merge_sort_top_down(char array[], int low, int high)
{
    if (low < high){
        int mid = (low + high)/2;
        merge_sort_top_down(array, low, mid);
        merge_sort_top_down(array, mid+1, high);
        merge(array, low, mid, high);
    }

    return;
}

/* 自底向上归并 */
void merge_sort_bottom_up(char array[], int length)
{
    int i = 0x01;

    for(; i < length; i *= 2){
        merge_pass(array, i, length);
    }

    return;
}


int main(void)
{
    char array[] = {5, 26, 37, 1, 11, 61, 15, 59, 48, 19, 88, 7, 9};
#if 1
    printf("original sort : \n");
    int i = 0x00;
    for (; i < sizeof(array); i++)
        printf("%d ", array[i]);
    printf("\n");
#endif

#if 1
    merge_sort_bottom_up(array, sizeof(array));
#else
    merge_sort_top_down(array, 0, sizeof(array)-1);
#endif
#if 1
    printf("merge sort : \n");
    i = 0x00;
    for (; i < sizeof(array); i++)
        printf("%d ", array[i]);
    printf("\n");

#endif

    return 0x00;
}

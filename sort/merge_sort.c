#include <stdio.h>
#include <stdlib.h>

void merge(char array[], int low, int m, int high)
{
    int i = low, j = m+1;

    char *tmp_array = (char *)calloc(1, high);
    if (NULL == tmp_array){
        printf("calloc error!\n");
        return;
    }

    char *p = tmp_array;
    while ((i <= m) && (j <= high)){
        if (array[i] < array[j]){
            *p = array[i++];
        }else{
            *p = array[j++];
        }
        p++;
    }

    while (i <= m){
        *p = array[i++];
        p++;
    }

    while (j <= high){
        *p = array[j++];
        p++;
    }

    int idx = 0x00, index = low;
    for(; index <= high; idx++, index++){
        array[index] = tmp_array[idx];
    }

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
        high = length-1;
        middle = i + step - 1;
        low = i;
        /*printf("--- %d, %d, %d, %d, %d----\n", i, high, middle, low, array[i]);*/
        merge(array, low, middle, high);
    }
    return;
}

void merge_sort(char array[], int length)
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

    merge_sort(array, sizeof(array));
#if 1
    printf("quick sort : \n");
    int i = 0x00;
    for (; i < sizeof(array); i++)
        printf("%d ", array[i]);
    printf("\n");
#endif

    return 0x00;
}

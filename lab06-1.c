#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int arr[], int len){
    int i, j;
    for(i = 0; i < len-1; i++){
        for(j = 0; j < len-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[100];
    int len = 0;
    int num;
    FILE *f1, *f2;

    f1 = fopen("input.txt", "r");
    if(f1 == NULL){
        printf("error\n");
        return 1;
    }

    printf("input: ");
    while(fscanf(f1, "%d", &num) != EOF && len < 100){
        arr[len++] = num;
        printf("%d ", num);
    }
    printf("\n");

    fclose(f1);


    BubbleSort(arr, len);


    f2 = fopen("output.txt", "w");
    if(f2 == NULL){
        printf("error\n");
        return 1;
    }

    printf("output: ");
    for(int i = 0; i < len; i++){
        fprintf(f2, "%d ", arr[i]);
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(f2);

    return 0;
}

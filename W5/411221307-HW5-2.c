#include <stdio.h>

int count = 0;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    count++;
}

int main(){
    int cases;
    scanf("%d", &cases);
    for(int z = 0; z < cases; z++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for(int i = n - 1; i > 0; i--){
            for(int j = 0; j <= i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
        count = 0;
    }
}
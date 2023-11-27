#include <stdio.h>
#include <string.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int arr[a][b];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < c; i++){
        int d, e, f;
        scanf("%d %d %d", &d, &e, &f);
        arr[d][e] = f;
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
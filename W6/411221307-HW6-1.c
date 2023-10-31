#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b){
    int c = *(int*)a;
    int d = *(int*)b;
    int primeA = 1, primeB = 1;
    if(c <= 1) primeA = 0;
    if(d <= 1) primeB = 0;
    for(int i = 2; i <= sqrt(c); i++){
        if(c % i == 0){
            primeA = 0;
            break;
        }
    }
    for(int i = 2; i <= sqrt(d); i++){
        if(d % i == 0){
            primeB = 0;
            break;
        }
    }
    if(primeA > primeB) return -1;
    if(primeA < primeB) return 1;
    if(primeA == primeB){
        if(primeA == 1){
            if(c > d) return -1;
            if(c < d) return 1;
        }
        if(primeA == 0){
            if(c < d) return -1;
            if(c > d) return 1;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), comp);
    for(int i = 0; i < n - 1; i++) printf("%d ", arr[i]);
    printf("%d", arr[n - 1]);
}
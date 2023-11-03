#include <stdio.h>
#include <stdlib.h>

int m;

int comp(const void *a, const void *b){
    int c = *(int*)a;
    int d = *(int*)b;
    if(c % m > d % m) return 1;
    if(c % m < d % m) return -1;
    if(c % m == d % m){
        if(abs(c % 2) > abs(d % 2)) return -1;
        if(abs(c % 2) < abs(d % 2)) return 1;
        if(abs(c % 2) == 1 && abs(d % 2) == 1){
            if(c > d) return -1;
            if(c < d) return 1;
        }
        if(c % 2 == 0 && d % 2 == 0){
            if(c > d) return 1;
            if(c < d) return -1;
        }
    }
}

int main(){
    int n;
    while(scanf("%d %d", &n, &m)){
        printf("%d %d\n", n, m);
        if(n == 0 && m == 0) return 0;
        int arr[n];
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), comp);
        for(int i = 0; i < n; i++) printf("%d\n", arr[i]);
    }
}
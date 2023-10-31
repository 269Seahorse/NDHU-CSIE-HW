#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int c = *(int*)a;
    int d = *(int*)b;
    if (c > d) return 1;
    if (c < d) return -1;
}

int main(){
    int n;
    float sum = 0, avg = 0;
    scanf("%d", &n);
    float l[n];
    for(int i = 0; i < n; i++){
        scanf("%f", &l[i]);
    }
    qsort(l, n, sizeof(int), compare);
    for(int i = 3; i < n - 3; i++){
        sum += l[i];
    }
    avg = sum / (n - 6);
    printf("%.2f", avg);
}
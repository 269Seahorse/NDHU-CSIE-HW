#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int a[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        qsort(a, n, sizeof(int), comp);
        int ans[3] = {0};
        ans[0] = a[(n - 1) / 2];
        int mid = a[n / 2];
        for(int i = 0; i < n; i++)
            if(a[i] == mid || a[i] == ans[0]) ans[1]++;
        ans[2] = mid - ans[0] + 1;
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
}
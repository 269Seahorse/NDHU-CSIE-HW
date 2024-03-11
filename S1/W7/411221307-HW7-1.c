#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int alg(int m, int n){
    int num = 0;
    for(int i = m; i <= n; i++){
        int a = i, t = 0;
        while(1){
            t++;
            if(a == 1){
                if(t > num) num = t;
                break;
            }
            else if(a & 1) a = 3 * a + 1;
            else(a >>= 1);
        }
    }
    return num;
}

int main(){
    int m, n, time;
    while(scanf("%d %d", &m, &n) != EOF){
        printf("%d %d ", m, n);
        if(m > n) swap(&m, &n);
        time = alg(m, n);
        printf("%d\n", time);
    }
}
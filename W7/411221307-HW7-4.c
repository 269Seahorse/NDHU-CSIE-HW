#include <stdio.h>

int main(){
    int n, k;
    while(scanf("%d %d", &n, &k)){
        if(!(n || k)) break;
        if(n == 1){
            printf("1\n");
            continue;
        }
        int a[n+1], b = n, c, pos = 1;
        for(int i = 1; i <= n; i++) a[i] = i;
        while(b > 1){
            int count = 0;
            while(count < k){
                if(pos > n) pos = 1;
                if(a[pos]) count++;
                pos++;
            }
            c = pos - 1;
            a[c] = 0;
            count = 0;
            while(count < k){
                if(pos > n) pos = 1;
                if(a[pos]) count++;
                pos++;
            }
            a[c] = a[pos-1];
            a[pos-1] = 0;
            pos = c + 1;
            b--;
        }
        if(a[c] == 1) printf("1\n");
        else printf("%d\n", n - (a[c] - 1) + 1);
    }
}
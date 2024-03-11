#include <stdio.h>

int main(){
    int a, tmp, ans = 0;
    scanf("%d", &a);
    while (a != 0){
        tmp = a % 10;
        a /= 10;
        ans = ans * 10 + tmp;
    }
    ans < 1000 ? printf("0%d", ans) : printf("%d", ans);
}
#include <stdio.h>

int main(){
    int n, digit = 0;
    scanf("%d", &n);
    char ans[33];
    while(n != 0){
        if(n & 1) ans[digit] = '1';
        else ans[digit] = '0';
        n >>= 1;
        digit++;
    }
    for(int i = digit - 1; i >= 0; i--) printf("%c", ans[i]);
}
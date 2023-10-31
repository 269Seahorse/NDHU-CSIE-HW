#include <stdio.h>

int main(){
    int a, b = -2147483647;
    for(int i = 0; i < 4; i++){
        scanf("%d", &a);
        if (a > b) b = a;
    }
    printf("%d", b);
}
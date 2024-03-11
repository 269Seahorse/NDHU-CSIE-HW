#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b <= c){
        printf("can not construct");
        return 0;
    }
    if (a * a + b * b == c * c) printf("right triangle");
    if (a * a + b * b > c * c) printf("acute triangle");
    if (a * a + b * b < c * c) printf("obtuse triangle");
}
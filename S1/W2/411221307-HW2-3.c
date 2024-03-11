#include <stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a > b) swap(&a, &b);
    if (c > d) swap(&c, &d);
    for(int i = a; i <= b; i++){
        if (i > c && i < d){
            printf("overlay");
            return 0;
        }
    }
    printf("no overlay");
}
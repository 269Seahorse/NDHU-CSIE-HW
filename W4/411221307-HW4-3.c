#include <stdio.h>

int main(){
    int n, count = 0;
    float avg = 0;
    scanf("%d", &n);
    int score[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &score[i]);
        avg += score[i];
    }
    avg = avg / n / 1.0;
    for(int i = 0; i < n; i++){
        if(score[i] < avg) count++;
    }
    printf("%d", count);
}
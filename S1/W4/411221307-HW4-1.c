#include <stdio.h>
#include <math.h>

int main(){
    int n;
    float sum = 0, idk = 0;
    scanf("%d", &n);
    float tmp[n];
    for (int i = 0; i < n; i++){
        float num;
        scanf("%f", &num);
        tmp[i] = num;
        sum += num;
    }
    float avg = sum / n / 1.0;
    for (int i = 0; i < n; i++){
        idk += ((tmp[i] - avg) * (tmp[i] - avg));
    }
    idk = idk / n / 1.0;
    idk = sqrt(idk);
    printf("%.2f", idk);
}
#include <stdio.h>
#include <math.h>

int main(){
    float km, money;
    scanf("%f", &km);
    money = (km - (km > 200) * (km - 200)) * 1.2 + (km > 200) * (km - (km > 200) * 200) * 1.2 * 0.75;
    money = round(money);
    printf("%.0f", money);
}
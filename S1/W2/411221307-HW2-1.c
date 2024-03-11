#include <stdio.h>
#include <math.h>

int main() {
    float a;
    scanf("%f", &a);
    a *= 100;
    printf("%.2f\n%.2f", round(a)/100.0, floor(a)/100.0);
}
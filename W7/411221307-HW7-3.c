#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} pos;

int comp(const void *a, const void *b){
    return (*(pos*)b).x - (*(pos*)a).x;
}

int main(){
    int cases;
    scanf("%d", &cases);
    for(int z = 0; z < cases; z++){
        int n;
        scanf("%d", &n);
        pos p[n];
        for(int i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
        qsort(p, n, sizeof(pos), comp);
        double maxy = 0;
        double total = 0;
        for(int i = 0; i < n; i++){
            if(p[i].y > maxy){
                double x =  p[i].x - (p[i].x - p[i-1].x) * (p[i].y - maxy) / (p[i].y - p[i-1].y);
                double y = maxy;
                total += sqrt((x - p[i].x) * (x - p[i].x) + (y - p[i].y) * (y - p[i].y));
                maxy = p[i].y;
            }
        }
        printf("%.2f\n", total);
    }
}
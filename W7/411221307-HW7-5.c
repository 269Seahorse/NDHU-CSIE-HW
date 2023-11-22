#include <stdio.h>

int main(){
    int pos[10001] = {0}, x, x2, h, minx = 20000, maxx = 0, tmp = -1;
    while(scanf("%d %d %d", &x, &h, &x2) != EOF){
        if(x < minx) minx = x;
        if(x2 > maxx) maxx = x2;
        for(int i = x; i < x2; i++) if(h > pos[i]) pos[i] = h;
    }
    for(int i = minx; i <= maxx; i++){
        if(pos[i] != tmp){
            printf("%d %d ", i, pos[i]);
            tmp = pos[i];
        }
    }
}
#include <stdio.h>
#include <string.h>

int main(){
    char num[1001];
    while(scanf("%s", num)){
        int odd = 0, even = 0, diff;
        if(num[0] == '0' && strlen(num) == 1) break;
        for(int i = 0; i < strlen(num); i++){
            if(i % 2 == 0) even += (num[i] - '0');
            if(i % 2 == 1) odd += (num[i] - '0');
        }
        if(odd >= even) diff = odd - even;
        else diff = even - odd;
        if(diff % 11 == 0) printf("%s is a multiple of 11.\n", num);
        else printf("%s is not a multiple of 11.\n", num);
    }
}
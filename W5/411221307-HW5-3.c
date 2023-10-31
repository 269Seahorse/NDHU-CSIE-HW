#include <stdio.h>
#include <string.h>

int main(){
    char num[1001];
    while(fgets(num, 1001, stdin) != NULL){
        int a[129];
        int min[2] = {0, 1001};
        int flag = 0;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < strlen(num); i++) a[num[i]]++;
        for(int j = 0; j < 100; j++){
            for(int i = 128; i > 31; i--){
                if(a[i] < min[1] && a[i] != 0){
                    min[0] = i;
                    min[1] = a[i];
                    flag = 1;
                }
            }
            if(flag == 1){
                printf("%d %d\n", min[0], min[1]);
                a[min[0]] = 0;
                min[1] = 1001;
                flag = 0;
            }
        }
        printf("\n");
    }
}
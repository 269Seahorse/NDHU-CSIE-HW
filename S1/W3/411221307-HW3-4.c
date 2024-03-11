#include <stdio.h>

int main(){
    char a[4];
    scanf("%s", a);
    for(int i = 0; i < 4; i++){
        if (a[i] == '4'){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
}
#include <stdio.h>
#include <string.h>

int main(){
    char s[20000];
    int period = 1;
    scanf("%[^\f]s", s);
    for(int i = 0; i < strlen(s); i++){
        if(period == 1 && s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
            period = 0;
        }
        if(period == 1 && s[i] >= 'A' && s[i] <= 'Z') period = 0;
        if(period == 1 && s[i] >= '0' && s[i] <= '9') period = 0;
        if(s[i] == '.' || s[i] == '!' || s[i] == '?') period = 1;
        printf("%c", s[i]);
    }
}
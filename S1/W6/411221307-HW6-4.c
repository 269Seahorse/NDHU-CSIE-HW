#include <stdio.h>
#include <string.h>

int main(){
    char s[20000];
    int ascii[127], len = 0, ans[2] = {-1, -1}, tmp = 0;
    memset(ascii, -1, sizeof(ascii));
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++){
        if(ascii[s[i]] + 1 > tmp) tmp = ascii[s[i]] + 1;
        ascii[s[i]] = i;
        if((i - tmp + 1) > len){
            len = (i - tmp + 1);
            ans[0] = tmp;
            ans[1] = i;
        }
    }
    for(int i = ans[0]; i <= ans[1]; i++) printf("%c", s[i]);
}
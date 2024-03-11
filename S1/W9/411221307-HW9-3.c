// #include <stdio.h>

// char s1[1000], s2[1000];

// void init(){
//     scanf("%s %s", s1, s2);
// }
//
int main() {
    init();
    char *str = s1;
    char *key = s2;
    int count;
    //add your code here
    count = 0;
    int len1 = 0, len2 = 0;
    for(int i = 0; str[i] != '\0'; i++) len1++;
    for(int i = 0; key[i] != '\0'; i++) len2++;
        for(int i = 0; i <= len1 - len2; i++){
        int flag = 0;
        for(int j = 0; j < len2; j++){
            if(str[i + j] != key[j]){
                flag = 1;
                break;
            }
        }
        if(!flag) count++;
    }
    //end of code
    printf("%d", count);
    return 0;
}

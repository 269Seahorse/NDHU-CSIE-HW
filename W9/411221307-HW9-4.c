// #include <stdio.h>

// char s[1000];

// void init(){
//     fgets(s, 1000, stdin);
// }

int main() {
    init();
    char *str = s;
    int sum;
    //add your code here
    sum = 0;
    int tmp = 0;
    char last = 'q';
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= '0' && str[i] <= '9' && !(last >= '0' && last <= '9')) tmp += str[i] - '0';
        else if(str[i] >= '0' && str[i] <= '9' && last >= '0' && last <= '9'){
            tmp *= 10;
            tmp += str[i] - '0';
        }
        else{
            sum += tmp;
            tmp = 0;
        }
        last = str[i];
    }
    //end of code
    printf("%d", sum);
    return 0;
}

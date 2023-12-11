#include <stdio.h>
#include <string.h>

typedef struct {
    char integer[1000];
    char decimal[1000];
} DeciVar;

int main(){
    DeciVar n, m;
    char input1[2001], input2[2001];
    scanf("%s", input1);
    scanf("%s", input2);
    char *tmp = strtok(input1, ".");
    if(tmp != NULL){
        strcpy(n.integer, tmp);
        tmp = strtok(NULL, ".");
        if(tmp != NULL) strcpy(n.decimal, tmp);
    }
    tmp = strtok(input2, ".");
    if(tmp != NULL){
        strcpy(m.integer, tmp);
        tmp = strtok(NULL, ".");
        if(tmp != NULL) strcpy(m.decimal, tmp);
    }
    int decsum[1001] = {0};
    int intsum[1001] = {0};
    int flag = 0;
    int declen = strlen(n.decimal) > strlen(m.decimal) ? strlen(n.decimal) : strlen(m.decimal);
    for(int i = strlen(n.decimal) - 1; i >= 0; i--){
        decsum[i] = (n.decimal[i] - '0');
    }
    for(int i = strlen(m.decimal) - 1; i >= 0; i--){
        decsum[i] += (m.decimal[i] - '0');
        if(decsum[i] >= 10 && i != 0){
            decsum[i] -= 10;
            decsum[i-1]++;
        }
        else if(decsum[i] >= 10 && i == 0){
            decsum[i] -= 10;
            flag = 1;
        }
    }
    int intlen = strlen(n.integer) > strlen(m.integer) ? strlen(n.integer) : strlen(m.integer);
    int count = 0;
    if(flag) intsum[0]++;
    for(int i = strlen(n.integer) - 1; i >= 0; i--){
        intsum[count] += (n.integer[i] - '0');
        count++;
    }
    count = 0;
    for(int i = strlen(m.integer) - 1; i >= 0; i--){
        intsum[count] += (m.integer[i] - '0');
        count++;
    }
    for(int i = 0; i < intlen; i++){
        if(intsum[i] >= 10){
            intsum[i] -= 10;
            intsum[i+1]++;
            if(i + 1 >= intlen) intlen++;
        }
    }
    for(int i = declen - 1; i >= 0; i--){
        if(decsum[i] == 0) declen--;
        else break;
    }
    for(int i = intlen - 1; i >= 0; i--) printf("%d", intsum[i]);
    if(declen > 0){
        printf(".");
        for(int i = 0; i < declen; i++) printf("%d", decsum[i]);
    }
}
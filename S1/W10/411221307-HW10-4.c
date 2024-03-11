#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d\n", &n);
    char b[69][69], b2[69][69];
    memset(b, 0, sizeof(b));
    int line = 0;
    while(scanf("%s", b[line]) != EOF) line++;
    memcpy(b2, b, sizeof(b));
    for(int num = 0; num < n; num++){
        for(int i = 0; i <= line; i++){
            for(int j = 0; j < strlen(b[0]); j++){
                if(b[i][j] == '1'){
                    int count = 0;
                    if(b[i+1][j] == '1') count++;
                    if(b[i+1][j+1] == '1') count++;
                    if(j > 0) if(b[i+1][j-1] == '1') count++;
                    if(i > 0) if(b[i-1][j] == '1') count++;
                    if(i > 0) if(b[i-1][j+1] == '1') count++;
                    if(i > 0 && j > 0) if(b[i-1][j-1] == '1') count++;
                    if(b[i][j+1] == '1') count++;
                    if(j > 0) if(b[i][j-1] == '1') count++;
                    if(count < 2) b2[i][j] = '0';
                    else if(count >= 4) b2[i][j] = '0';
                }
                else if(b[i][j] == '0'){
                    int count = 0;
                    if(b[i+1][j] == '1') count++;
                    if(b[i+1][j+1] == '1') count++;
                    if(j > 0) if(b[i+1][j-1] == '1') count++;
                    if(i > 0) if(b[i-1][j] == '1') count++;
                    if(i > 0) if(b[i-1][j+1] == '1') count++;
                    if(i > 0 && j > 0) if(b[i-1][j-1] == '1') count++;
                    if(b[i][j+1] == '1') count++;
                    if(j > 0) if(b[i][j-1] == '1') count++;
                    if(count == 3) b2[i][j] = '1';
                }
            }
        }
        memcpy(b, b2, sizeof(b2));
    }
    for(int i = 0; i < line; i++){
        for(int j = 0; j < strlen(b[0]); j++){
            printf("%c", b[i][j]);
        }
        printf("\n");
    }
}
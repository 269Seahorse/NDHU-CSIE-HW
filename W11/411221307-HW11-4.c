/*
Refuse to write recursion, start from you and me!!
*/

#include <stdio.h>

int main(){
    char f[1024] = {0}, stack[1024] = {0}, last = 'e';
    fgets(f, 1024, stdin);
    int ans = 0, tmp = 0, index = 0, G = -1, sum = 0, tmpa[100] = {0}, tmpb[100] = {0}, status[100] = {0};
    for(int i = 0; f[i] != '\0'; i++){
        if(f[i] == 'F'){
            stack[index] = f[i];
            index++;
        }
        if(f[i] == 'G'){
            stack[index] = f[i];
            index++;
            G++;
            status[G] = 1;
        }
        if(f[i] >= '0' && f[i] <= '9' && !(last >= '0' && last <= '9')) tmp += f[i] - '0';
        else if(f[i] >= '0' && f[i] <= '9' && last >= '0' && last <= '9'){
            tmp *= 10;
            tmp += f[i] - '0';
        }
        else if(!(f[i] >= '0' && f[i] <= '9') && last >= '0' && last <= '9'){
            sum += tmp;
            tmp = 0;
            if(stack[index - 1] == 'G' && status[G] == 2){
                tmpb[G] = sum;
                ans = sum;
                sum = 0;
            }
            if(stack[index - 1] == 'G' && status[G] == 1){
                tmpa[G] = sum;
                ans = sum;
                sum = 0;
            }
            else{
                ans = sum;
                sum = 0;
            }
        }
        if(f[i] == ',') status[G] = 2;
        if(f[i] == ')'){
            if(stack[index - 1] == 'F'){
                if(status[G] == 1){
                    tmpa[G] = ans * 3 + 1;
                    ans = ans * 3 + 1;
                }
                if(status[G] == 2){
                    tmpb[G] = ans * 3 + 1;
                    ans = ans * 3 + 1;
                }
                if(G == -1) ans = ans * 3 + 1;
            }
            if(stack[index - 1] == 'G'){
                status[G] = 0;
                G--;
                if(status[G] == 1){
                    tmpa[G] = tmpa[G + 1] * tmpb[G + 1] - 3;
                    ans = tmpa[G + 1] * tmpb[G + 1] - 3;
                }
                if(status[G] == 2){
                    tmpb[G] = tmpa[G + 1] * tmpb[G + 1] - 3;
                    ans = tmpa[G + 1] * tmpb[G + 1] - 3;
                }
                if(G == -1) ans = tmpa[G + 1] * tmpb[G + 1] - 3;
                tmpa[G + 1] = 0;
                tmpb[G + 1] = 0;
            }
            index--;
        }
        last = f[i];
    }
    printf("%d", ans);
}
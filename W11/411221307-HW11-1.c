/*******************************************
function name: replace
description: When mode is 1, replace the first target finded in source with the replacement.
             When mode is 2, replace left-most target by replacement until there are no targets in the source.
return value: Return the result after replace.
*******************************************/
// #include <stdio.h>
//code start
#include <string.h>
#include <stdlib.h>

char *replace(char *source, char *target, char *replacement, int mode) {
    char *res = malloc(sizeof(source));
    memset(res, 0, sizeof(res));
    if(mode == 1){
        for(int i = 0; i < strlen(source) - strlen(target) + 1; i++){
            if(strncmp(&source[i], target, strlen(target)) == 0){
                strncpy(&res[i], replacement, strlen(replacement));
                strncpy(&res[i + strlen(replacement)], &source[i + strlen(target)], strlen(source) - i - strlen(target));
                return res;
            }
            else res[i] = source[i];
        }
        return res;
    }
    if(mode == 2){
        for(int i = 0; source[i] != '\0'; i++){
            if(strncmp(&source[i], target, strlen(target)) == 0){
                strncpy(&res[i], replacement, strlen(replacement));
                strncpy(&res[i + strlen(replacement)], &source[i + strlen(target)], strlen(source) - i - strlen(target));
                strcpy(source, res);
                memset(res, 0, sizeof(res));
                // printf("%s\n", source);
                i = -1;
            }
            else res[i] = source[i];
        }
        return res;
    }
}
//code end

// int main(){
//     char source[1001], target[1001], replacement[1001];
//     int mode;
//     scanf("%s %s %s %d", source, target, replacement, &mode);
//     printf("%s", replace(source, target, replacement, mode));
// }
/*************************************************************
function name: convertToDifferentBase
description: Convert a decimal number @dec to the number with different @base and store the result as a string in result
return vaule: Result after convert.
notice: The letter you see in the number should be upper case.
*************************************************************/
// #include <stdio.h>
//code start
#include <stdlib.h>
#include <string.h>

char *convertToDifferentBase(int dec, int base, char *result) {
    int index = 0;
    while(dec != 0){
        int rem;
        rem = dec % base;
        result[index] = rem < 10 ? '0' + rem : 'A' + (rem - 10);
        dec /= base;
        index++;
    }
    char *realres = malloc(sizeof(result));
    memset(realres, 0, sizeof(realres));
    for(int i = index - 1; i >= 0; i--) realres[index - 1 - i] = result[i];
    return realres;
}

//code end

// int main(){
//     char result[1001];
//     int dec, base;
//     scanf("%d %d", &dec, &base);
//     printf("%s", convertToDifferentBase(dec, base, result));
// }
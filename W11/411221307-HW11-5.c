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
    memset(result, 0, sizeof(result));
    char a[2] = "";
    dec % base < 10 ? (a[0] = '0' + (dec % base)) : (a[0] = 'A' + (dec % base) - 10);
    if(dec >= base) convertToDifferentBase(dec / base, base, result);
    strcat(result, a);
    return result;
}

//code end

// int main(){
//     char result[1001];
//     int dec, base;
//     scanf("%d %d", &dec, &base);
//     printf("%s", convertToDifferentBase(dec, base, result));
// }
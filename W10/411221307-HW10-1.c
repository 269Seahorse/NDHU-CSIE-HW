#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char studentID[20];
    int programming, programmingLab, calculus;
} Student;

int comp(const void *a, const void *b){
    return (*(Student*)b).programming + (*(Student*)b).programmingLab + (*(Student*)b).calculus - (*(Student*)a).programming - (*(Student*)a).programmingLab - (*(Student*)a).calculus;
}

int main(){
    int n;
    scanf("%d", &n);
    Student std[n];
    for(int i = 0; i < n; i++) scanf("%s %d %d %d", std[i].studentID, &std[i].programming, &std[i].programmingLab, &std[i].calculus);
    qsort(std, n, sizeof(Student), comp);
    for(int i = 0; i < 3; i++) printf("%s\n", std[i].studentID);
}
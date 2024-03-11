// #include <stdio.h>

// int arr[9] = {1,2,3,4,5,6,7,8,9};

// void init(int **a, int **b){
//     int c, d;
//     scanf("%d %d", &c, &d);
//     *a = &arr[c];
//     *b = &arr[d];
// }

int main() {
    int *a, *b;
    init(&a, &b);
    int sum;
    //add your code here
    sum = 0;
    for(int *i = a; i < b; i++){
        sum += *i;
    }
    //end of code
    printf("%d", sum);
    return 0;
}

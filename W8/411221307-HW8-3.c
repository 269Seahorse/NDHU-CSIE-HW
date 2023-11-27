#include <stdio.h>
#include <string.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[n+2][m+2];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[j][i]);
        }
    }
    for(int i = 0; i < n+2; i++) arr[i][0] = 0;
    for(int i = 0; i < n+2; i++) arr[i][m+1] = 0;
    for(int i = 0; i < m+2; i++) arr[0][i] = 0;
    for(int i = 0; i < m+2; i++) arr[n+1][i] = 0;
    int x = 1, y = 1;
    while(1){
        while(1){
            if(arr[x][y] != 0) printf("%d ", arr[x][y]);
            arr[x][y] = 0;
            if(arr[x+1][y] == 0) break;
            else x += 1;
        }
        while(1){
            if(arr[x][y] != 0) printf("%d ", arr[x][y]);
            arr[x][y] = 0;
            if(arr[x][y+1] == 0) break;
            else y += 1;
        }
        while(1){
            if(arr[x][y] != 0) printf("%d ", arr[x][y]);
            arr[x][y] = 0;
            if(arr[x-1][y] == 0) break;
            else x -= 1;
        }
        while(1){
            if(arr[x][y] != 0) printf("%d ", arr[x][y]);
            arr[x][y] = 0;
            if(arr[x][y-1] == 0) break;
            else y -= 1;
        }
        if(arr[x+1][y] == 0 && arr[x-1][y] == 0 && arr[x][y+1] == 0 && arr[x][y-1] == 0) break;
    }
}
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int data[n][2];
        for(int i = 0; i < n; i++) data[i][0] = i; //position
        for(int i = 0; i < n; i++) data[i][1] = 0; //height
        while(1){
            int a, b;
            char c[5], d[5];
            scanf("%s", c);
            if(strcmp(c, "quit") == 0) break;
            scanf("%d %s %d", &a, d, &b);
            if(a == b || data[a][0] == data[b][0]) continue;
            if(strcmp(c, "move") == 0){
                if(strcmp(d, "onto") == 0){
                    for(int i = 0; i < n; i++){
                        if(data[i][0] == data[a][0] && data[i][1] > data[a][1]){
                            data[i][0] = i;
                            data[i][1] = 0;
                        }
                        if(data[i][0] == data[b][0] && data[i][1] > data[b][1]){
                            data[i][0] = i;
                            data[i][1] = 0;
                        }
                    }
                    data[a][0] = data[b][0];
                    data[a][1] = data[b][1] + 1;
                }
                else if(strcmp(d, "over") == 0){
                    int m = 0;
                    for(int i = 0; i < n; i++){
                        if(data[i][0] == data[a][0] && data[i][1] > data[a][1]){
                            data[i][0] = i;
                            data[i][1] = 0;
                        }
                    }
                    for(int i = 0; i < n; i++){
                        if(data[i][0] == data[b][0] && data[i][1] > m) m = data[i][1];
                    }
                    data[a][0] = data[b][0];
                    data[a][1] = m + 1;
                }
            }
            if(strcmp(c, "pile") == 0){
                if(strcmp(d, "onto") == 0){
                    for(int i = 0; i < n; i++){
                        if(data[i][0] == data[b][0] && data[i][1] > data[b][1]){
                            data[i][0] = i;
                            data[i][1] = 0;
                        }
                    }
                    int m = data[b][1] + 1, tmp1 = data[a][1], tmp0 = data[a][0];
                    for(int i = 0; i < n; i++){
                        if(data[i][0] == tmp0 && data[i][1] >= tmp1){
                            data[i][0] = data[b][0];
                            data[i][1] = m - tmp1 + data[i][1];
                        }
                    }
                }
                else if(strcmp(d, "over") == 0){
                    int m = 0, tmp1 = data[a][1], tmp0 = data[a][0];
                    for(int i = 0; i < n; i++){
                        if(data[i][0] == data[b][0] && data[i][1] > m) m = data[i][1];
                    }
                    m++;
                    for(int i = 0; i < n; i++){
                        if(data[i][0] == tmp0 && data[i][1] >= tmp1){
                            data[i][0] = data[b][0];
                            data[i][1] = m - tmp1 + data[i][1];
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            printf("%d:", i);
            for(int j = 0; j < n; j++){
                int f = 0;
                for(int k = 0; k < n; k++){
                    if(data[k][0] == i && data[k][1] == j){
                        printf(" %d", k);
                        f = 1;
                        break;
                    }
                }
                if(!f) break;
            }
            printf("\n");
        }
    }
}
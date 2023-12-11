#include <stdio.h>
#include <stdlib.h>

typedef struct position{
    int x;
    int y;
    struct position *next;
} pos;

typedef struct queue{
    int size;
    pos *first, *last;
} q;

void init(q *qq){
    qq -> size = 0;
    qq -> first = NULL;
    qq -> last = NULL;
}

void add(q *qq, int x, int y){
    pos *tmp = (pos *)malloc(sizeof(pos));
    tmp -> x = x;
    tmp -> y = y;
    tmp -> next = NULL;
    if(qq -> first == NULL) qq -> first = tmp;
    else qq -> last -> next = tmp;
    qq -> last = tmp;
    qq -> size++;
}

pos del(q *qq){
    pos *tmp = qq -> first;
    qq -> first = tmp -> next;
    if(qq -> first == NULL) qq -> last = NULL;
    qq -> size--;
    return *tmp;
}

int main(){
    int n;
    scanf("%d\n", &n);
    char b[11][11];
    for(int cases = 0; cases < n; cases++){
        int black = 0, white = 0;
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 10; j++){
                scanf("%c", &b[i][j]);
            }
        }
        for(int i = 0; i < 11; i++) b[0][i] = 69;
        for(int i = 0; i < 11; i++) b[10][i] = 69;
        for(int i = 0; i < 11; i++) b[i][0] = 69;
        for(int i = 0; i < 11; i++) b[i][10] = 69;
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                if(b[i][j] == 'O') white++;
                if(b[i][j] == 'X') black++;
            }
        }
        q remain;
        init(&remain);
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                if(b[i][j] == '.'){
                    int col = 0, tmp = 0, invalid = 0;
                    add(&remain, i, j);
                    while(remain.size > 0){
                        pos t = del(&remain);
                        b[t.x][t.y] = 69;
                        if(b[t.x-1][t.y] == '.'){
                            add(&remain, t.x-1, t.y);
                            b[t.x-1][t.y] = 69;
                        }
                        if(b[t.x-1][t.y] == 'O') {
                            if(col == 2) invalid = 1;
                            col = 1;
                        }
                        if(b[t.x-1][t.y] == 'X'){
                            if(col == 1) invalid = 1;
                            col = 2;
                        }
                        if(b[t.x+1][t.y] == '.'){
                            add(&remain, t.x+1, t.y);
                            b[t.x+1][t.y] = 69;
                        }
                        if(b[t.x+1][t.y] == 'O'){
                            if(col == 2) invalid = 1;
                            col = 1;
                        }
                        if(b[t.x+1][t.y] == 'X'){
                            if(col == 1) invalid = 1;
                            col = 2;
                        }
                        if(b[t.x][t.y-1] == '.'){
                            add(&remain, t.x, t.y-1);
                            b[t.x][t.y-1] = 69;
                        }
                        if(b[t.x][t.y-1] == 'O'){
                            if(col == 2) invalid = 1;
                            col = 1;
                        }
                        if(b[t.x][t.y-1] == 'X'){
                            if(col == 1) invalid = 1;
                            col = 2;
                        }
                        if(b[t.x][t.y+1] == '.'){
                            add(&remain, t.x, t.y+1);
                            b[t.x][t.y+1] = 69;
                        }
                        if(b[t.x][t.y+1] == 'O'){
                            if(col == 2) invalid = 1;
                            col = 1;
                        }
                        if(b[t.x][t.y+1] == 'X'){
                            if(col == 1) invalid = 1;
                            col = 2;
                        }
                        tmp++;
                    }
                    if(!invalid){
                        if(col == 1) white += tmp;
                        if(col == 2) black += tmp;
                    }
                }
            }
        }
        printf("Black %d White %d\n", black, white);
    }
}
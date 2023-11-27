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
    scanf("%d", &n);
    int maze[n+2][n+2];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    for(int i = 0; i < n+2; i++) maze[i][0] = 1;
    for(int i = 0; i < n+2; i++) maze[i][n+1] = 1;
    for(int i = 0; i < n+2; i++) maze[0][i] = 1;
    for(int i = 0; i < n+2; i++) maze[n+1][i] = 1;
    q remain;
    init(&remain);
    add(&remain, 1, 1);
    while(remain.size > 0){
        pos t = del(&remain);
        maze[t.x][t.y] = 1;
        if(t.x == n && t.y == n){
            printf("Yes");
            return 0;
        }
        if(maze[t.x-1][t.y] == 0){
            add(&remain, t.x-1, t.y);
            maze[t.x-1][t.y] = 1;
        }
        if(maze[t.x+1][t.y] == 0){
            add(&remain, t.x+1, t.y);
            maze[t.x+1][t.y] = 1;
        }
        if(maze[t.x][t.y-1] == 0){
            add(&remain, t.x, t.y-1);
            maze[t.x][t.y-1] = 1;
        }
        if(maze[t.x][t.y+1] == 0){
            add(&remain, t.x, t.y+1);
            maze[t.x][t.y+1] = 1;
        }
    }
    printf("No");
}
#include <stdio.h>

typedef struct {
    int sid, stdid, course;
} course;

typedef struct {
    int sid, score;
} score;

typedef struct {
    int stdid, score, num;
} fail;

int main(){
    int m, n, ans1 = 0, ans2 = 0, num = 0;
    scanf("%d %d", &m, &n);
    course c[m];
    score s[n];
    fail f[1001];
    int stdid[1001];
    for(int i = 0; i < 1001; i++){
        f[i].num = 0;
        f[i].score = 0;
        f[i].stdid = 0;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &c[i].sid, &c[i].stdid, &c[i].course);
        ans1++;
        for(int j = 0; j < i; j++) if(c[j].stdid == c[i].stdid){
            ans1--;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d", &s[i].sid, &s[i].score);
        f[s[i].sid].score += s[i].score;
        f[s[i].sid].num++;
        for(int j = 0; j < m; j++){
            if(s[i].sid == c[j].sid) f[s[i].sid].stdid = c[j].stdid;
        }
    }
    int flag = 0;
    for(int i = 0; i < 1001; i++){
        if(f[i].num != 0){
            if(f[i].score / f[i].num < 60){
                for(int j = 0; j < num; j++){
                    if(f[i].stdid == stdid[j]){
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    ans2++;
                    stdid[num] = f[i].stdid;
                    num++;
                }
                flag = 0;
            }
        }
    }
    printf("%d %d", ans1, ans2);
}
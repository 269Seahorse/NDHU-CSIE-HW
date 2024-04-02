#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int t = 0; t < n; t++){
        int a, b;
        cin >> a >> b;
        int stx, sty;
        cin >> stx >> sty;
        int draw[a + 1][b * 2 + 1] = {0};
        for(int i = 0; i < a + 1; i++){
            for(int j = 0; j < b * 2 + 1; j++){ //1 | 2 _ 3 
                if(i != a){
                    if(j & 1) draw[i][j] = 2;
                    else draw[i][j] = 1;
                }
                else{
                    if(j & 1) draw[i][j] = 2;
                }
            }
        }
        struct p{
            int x, y;
        };
        stack<p> stk;
        while(!stk.empty()) stk.pop();
        p tmp;
        tmp.x = stx - 1;
        tmp.y = sty * 2 - 1;
        stk.push(tmp);
        for(int count = a * b - 1; count > 0; count--){
            char c;
            cin >> c;
            if(c == 'U'){
                tmp.x++;
                draw[tmp.x][tmp.y] = 0;
                stk.push(tmp);
            }
            if(c == 'D'){
                draw[tmp.x][tmp.y] = 0;
                tmp.x--;
                stk.push(tmp);
            }
            if(c == 'L'){
                tmp.y -= 2;
                draw[tmp.x][tmp.y + 1] = 0;
                stk.push(tmp);
            }
            if(c == 'R'){
                tmp.y += 2;
                draw[tmp.x][tmp.y - 1] = 0;
                stk.push(tmp);
            }
            if(c == 'F'){
                int num;
                cin >> num;
                for(int i = 0; i < num; i++) stk.pop();
                count++;
                tmp = stk.top();
            }
        }
        for(int i = a; i >= 0; i--){
            for(int j = 0; j < b * 2 + 1; j++){
                if(i == a && j == b * 2) continue;
                if(draw[i][j] == 1) cout << "|";
                if(draw[i][j] == 2) cout << "_";
                if(draw[i][j] == 0) cout << " ";
            }
            cout << endl;
        }
        if(t != n - 1) cout << endl;
    }
}

/*
 _ _ _
|_|_|_|
|_|_|_|

2*3 -> 3*7
*/
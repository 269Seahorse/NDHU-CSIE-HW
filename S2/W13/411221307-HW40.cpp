#include <bits/stdc++.h>
using namespace std;

struct pos{
    double x;
    double y;
};

int comp(const void *a, const void *b){
    return (*(pos*)b).x - (*(pos*)a).x;
}

int main(){
    int cases;
    cin >> cases;
    for(int z = 0; z < cases; z++){
        if(z) cout << endl; 
        int n;
        cin >> n;
        pos p[n];
        for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
        qsort(p, n, sizeof(pos), comp);
        double maxy = 0;
        double total = 0;
        for(int i = 0; i < n; i++){
            if(p[i].y > maxy){
                double x = (p[i].x - p[i-1].x) * (p[i].y - maxy) / (p[i].y - p[i-1].y);
                double y = maxy;
                total += sqrt((x) * (x) + (y - p[i].y) * (y - p[i].y));
                maxy = p[i].y;
            }
        }
        printf("%.2f", total);
    }
}
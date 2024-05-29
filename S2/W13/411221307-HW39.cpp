//sol 1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    for(int z = 1; z <= cases; z++){
        if(z != 1) cout << endl;
        int n;
        cin >> n;
        int train[n + 1];
        for(int i = 1; i <= n; i++) cin >> train[i];
        int dp[2][n + 1] = {0}, ans = 0; //dp[0] is LIS. dp[1] is LDS
        for(int i = n; i > 0; i--){
            dp[0][i] = 1;
            dp[1][i] = 1; //set the current seg to 1 (because in default it hasn't been linked)
            for(int j = n; j > i; j--){
                if(train[i] > train[j]) dp[0][i] = max(dp[0][i], dp[0][j] + 1); //if heavier, you can either choose the current one or the new one + 1
                else dp[1][i] = max(dp[1][i], dp[1][j] + 1); //same as above
            }
            ans = max(ans, dp[0][i] + dp[1][i] - 1);
        }
        cout << ans;
    }
}

//sol 2

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    for(int z = 1; z <= cases; z++){
        if(z != 1) cout << endl;
        int n, tmp;
        cin >> n;
        int train[2 * n];
        for(int i = 0; i < n; i++){
            cin >> tmp;
            train[n - i - 1] = tmp;
            train[n + i] = tmp;
        }
        vector<int> dp;
        for(int i = 0; i < 2 * n; i++){ //reverse then add back original test case and find LDS
            int lds = 1;
            for(int j = 0; j < i; j++){
                if(train[i] < train[j] && dp[j] + 1 > lds) lds = dp[j] + 1; 
            }
            dp.push_back(lds);
        }
        int ans = 0;
        for(int i = 0; i < 2 * n; i++){
            if(dp[i] > ans) ans = dp[i];
        }
        cout << ans;
    }
}

//god damn dp

// DREAM PLACE DREAM PLACE
// もっと高く高く
// 夢を超えて ねえ

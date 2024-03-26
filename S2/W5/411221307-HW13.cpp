#include <bits/stdc++.h>
using namespace std;

class matrix{
private:
    vector<vector<int>> matrix;

    int n = 0;

public:
    void scan(){
        cin >> n;
        matrix.resize(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }
    }

    void print(){
        if(n == 0){
            cout << "No element in matrix can be printed.\n";
            return;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";
    }

    void right(){
        if(n == 0){
            cout << "No element in matrix can be rotated.\n";
            return;
        }
        vector<vector<int>> tmp;
        tmp.resize(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                tmp[i][j] = matrix[n - 1 - j][i];
            }
        }
        matrix = tmp;
    }

    void left(){
        if(n == 0){
            cout << "No element in matrix can be rotated.\n";
            return;
        }
        vector<vector<int>> tmp;
        tmp.resize(n, vector<int>(n));
        for(int t = 0; t < 3; t++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    tmp[i][j] = matrix[n - 1 - j][i];
                }
            }
            matrix = tmp;
        }
    }
};

int main(){
    string str;
    matrix m;
    while(true){
        cin >> str;
        if(str == "stop") return 0;
        else if(str == "rotate"){
            string str2;
            cin >> str2;
            if(str2 == "left") m.left();
            else if(str2 == "right") m.right();
            else cout << "unknown\n";
        }
        else if(str == "print") m.print();
        else if(str == "scan") m.scan();
        else cout << "unknown\n";
    }
}
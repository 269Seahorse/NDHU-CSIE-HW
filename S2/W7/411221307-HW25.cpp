#include <bits/stdc++.h>
using namespace std;

class oop {
private:
    vector<int> st, av;
    int f;

public:
    oop(vector<int> _st, vector<int> _av, int _f): f(_f) {
        st.assign(_st.begin(), _st.end());
        av.assign(_av.begin(), _av.end());
        sort(st.begin(), st.end());
        sort(av.begin(), av.end());
    }

    void ans() const {
        int a = f / 2 - !(f & 1);
        cout << "(Street: " << st[a] << ", Avenue: " << av[a] << ")" << endl; 
    }
};

int main() {
	int cases;
	cin >> cases;
	for(int z = 0; z < cases; z++) {
		int s, a, f;
        cin >> s >> a >> f;
        // int st[f], av[f];
        vector<int> st(f), av(f);
        for(int i = 0; i < f; i++) {
            cin >> st[i] >> av[i];
        }
        oop func(st, av, f);
        // sort(st, st + f);
        // sort(av, av + f);
        // int ans = f / 2 - !(f & 1);
		// cout << "(Street: " << st[ans] << ", Avenue: " << av[ans] << ")" << endl; 
        func.ans();
	}
}

// so why use oop

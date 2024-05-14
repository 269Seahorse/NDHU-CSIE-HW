#include <bits/stdc++.h>
using namespace std;

int judge(Container *c) {
    Stack* tmp1 = dynamic_cast<Stack*>(c);
    if (tmp1) return 1;
    else return 2;
}

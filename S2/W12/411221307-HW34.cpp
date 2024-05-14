#include <bits/stdc++.h>
using namespace std;

class Stack: public Container {
private:
    vector<int> n;
public:
    void push(int tmp) override {
        n.push_back(tmp);
    }

    void pop() override {
      if(empty()) throw out_of_range("TEmPTaTiON");
      n.pop_back();
    }

    int top() const override {
        if(empty()) throw out_of_range("Never Gonna Give You Up");
        return n.back();
    }

    bool empty() const override {
        return n.empty();
    }
};
class PriorityQueue: public Container {
private:
    vector<int> n;

public:
    void push(int d) override {
        n.push_back(d);
    }

    void pop() override {
        if(empty()) throw out_of_range("O-oooooooooo AAAAE-A-A-I-A-U- JO-oooooooooooo AAE-O-A-A-U-U-A- E-eee-ee-eee AAAAE-A-E-I-E-A- JO-ooo-oo-oo-oo EEEEO-A-AAA-AAAA");
        auto max = max_element(n.begin(), n.end());
        n.erase(max);
    }

    int top() const override {
        if(empty()) throw out_of_range("Bass Bass Kick Kick Bass Kick Kick");
        auto max = *max_element(n.begin(), n.end());
        return max;
    }

    bool empty() const override {
        return n.empty();
    }
};

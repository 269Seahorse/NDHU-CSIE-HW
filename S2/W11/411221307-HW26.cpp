#include <bits/stdc++.h>
using namespace std;

class PokerCard
{
public:
    PokerCard(std::string s, int f)
    {
        suit = s;
        face = f;
    }
    friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)
    {
        out<<"["<<p.face<<" of "<<p.suit<<"]";
        return out;
    }
    string getSuit() const {
        return suit;
    }

    int getFace() const {
        return face;
    }
    //Please finish the comparison operator override
    //compare face first, if the same then compare suit 
    //請完成比較運算子多載
    //先比較 face ， face 一樣再比較 suit
    //1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
    //spade > heart > diamond > club
    bool operator>(PokerCard &b)
    {
        if(face == b.getFace()) {
            map<string, int> f = {
                {"spade", 4},
                {"heart", 3},
                {"diamond", 2},
                {"club", 1}
            };
            return f[suit] > f[b.getSuit()];
        }
        else return ((face + 13) % 15) > ((b.getFace() + 13) % 15);
    }
    bool operator<(PokerCard &b)
    {
        if(face == b.getFace()) {
            map<string, int> f = {
                {"spade", 4},
                {"heart", 3},
                {"diamond", 2},
                {"club", 1}
            };
            return f[suit] < f[b.getSuit()];
        }
        else return ((face + 13) % 15) < ((b.getFace() + 13) % 15);
    }
    bool operator==(PokerCard &b)
    {
        return (suit == b.getSuit() && face == b.getFace());
    }

private:
    std::string suit;
    int face;
};
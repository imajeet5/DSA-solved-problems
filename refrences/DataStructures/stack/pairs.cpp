#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U>
class Pairs
{
private:
    T x;
    U y;

public:
    Pairs()
    {
    }
    Pairs(T x, U y)
    {
        this->x = x;
        this->y = y;
    }

    void setX(T x)
    {
        this->x = x;
    };
    T getX()
    {
        return x;
    }
    void setY(U y)
    {
        this->y = y;
    }
    U getY()
    {
        return y;
    }
};

int main(int argc, char const *argv[])
{
    Pairs<int, char> p;
    p.setX(1);
    p.setY('a');

    cout << p.getX() << " " << p.getY() << endl;

    Pairs<int, int> x(4, 5);
    Pairs<Pairs<int, int>, char> triplet(x, 'z');

    cout << triplet.getX().getX() << " " << triplet.getX().getY() << " " << triplet.getY() << endl;
    return 0;
}
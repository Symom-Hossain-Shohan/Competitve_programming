#include<bits/stdc++.h>
using namespace std;

class prepost
{
    int x;
    public:
    prepost()
    {
        x=0;
    }

    prepost operator++()
    {
        prepost r;
        r.x=++x;
        return r;
    }
    prepost operator++(int)
    {
        prepost r;
        r.x=x++;
        return r;
    }
    void show()
    {
        cout << x << endl;
    }
};

int main()
{
    prepost a;
    a.show();
    prepost b;
    b=++a;
    b.show();
    a.show();
}
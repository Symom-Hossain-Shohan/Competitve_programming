#include<bits/stdc++.h>

using namespace std;

class rec
{
    double height,width;
    public:
    void getData()
    {
        cin >> height >> width ;
    }
    friend void area(rec a);
    friend class chotobhai;
};

class  chotobhai
{
    public:
    void area(rec a)
    {
        cout << a.width *a.height << endl;
    }
};

void area(rec a)
{
    cout << setprecision(2) << fixed << a.height*a.width << endl;
}

int main()
{
    rec shawon;
    shawon.getData();
    area(shawon);
    chotobhai b;
    b.area(shawon);
}
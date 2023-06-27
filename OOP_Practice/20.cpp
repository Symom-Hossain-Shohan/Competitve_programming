#include<bits/stdc++.h>
using namespace std;

class Shape
{
    protected:
    int height,base;
    public:
    void getData()
    {
        cin >> height >> base ;
    }
    virtual void area()=0;
};

class rectangle: public Shape
{
    public:
    void area()
    {
        cout << height*base << endl;
    }
};

class triangle: public Shape
{
    public:
    void area()
    {
        cout << .5*height*base << endl;
    }
};

int main()
{
    triangle t;
    rectangle r;
    t.getData();
    t.area();
    r.getData();
    r.area();
}
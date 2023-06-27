#include<bits/stdc++.h>
using namespace std;

class Shape
{
    public:
    virtual void show()
    {
        cout << "This is a Shape\n";
    }
};

class Triangel: public Shape
{
    public:
    void show()
    {
        cout << "This is a Triangle\n";
    }
};

class Rectangle: public Shape
{
    public:
    void show()
    {
        cout << "This is a Rectangle\n";
    }
};

int main()
{
    Shape *p,ss;
    Triangel a;
    Rectangle b;
    p=&ss;
    p->show();
    p=&a;
    p->show();
    p=&b;
    p->show();
}
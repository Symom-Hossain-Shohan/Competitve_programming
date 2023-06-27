#include<bits/stdc++.h>
using namespace std;

class Rec{
    double length,width;
    public:
    void input_value()
    {
        cin >> length >> width ;
    }
    double area()
    {
        return  length *width ;
    }
    void output_value()
    {
        cout << "Length =" << length << endl;
        cout << "Width =" << width << endl;
    }
};


int main()
{
    cout << setprecision(2) << fixed;
    Rec a;
    a.input_value();
    a.output_value();
    double ar=a.area();
    cout << ar << endl;
}
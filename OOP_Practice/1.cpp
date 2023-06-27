#include<bits/stdc++.h>

using namespace std;

class BOX{
    public:
    double length,height,breadth;

    void input_value()
    {
        cin >> length >> height >> breadth ;
    }
    void print_value()
    {
        cout << length <<" " << height<< " " << breadth<< " " << endl;
    }
    double Voulume()
    {
        return length*height*breadth;
    }
};

int main()
{
    BOX a,b;
    a.input_value();
    b.input_value();

    double va,vb;
    cout << setprecision(4) << fixed ;
    va=a.Voulume();
    vb=b.Voulume();
    a.print_value();
    cout << va << endl;
    b.print_value();
    cout << vb << endl;
}
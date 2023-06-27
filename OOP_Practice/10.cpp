#include<bits/stdc++.h>
using namespace std;

class cmplx
{
    double img,real;
    public:
    cmplx(){};
    cmplx(double x)
    {
        real=img=x;
    }
    cmplx(double a, double b)
    {
        real=a;
        img=b;
    }
    cmplx(cmplx &c)
    {
        real=c.real;
        img=c.img;
    }

    friend void sum(cmplx a, cmplx b);
};

void sum(cmplx a, cmplx b)
{
    cout << a.real+b.real << " " << a.img+b.img<< endl;
}

int main()
{
    cmplx a,b(4.5),c(3.3,4.4);
    a=c;
    sum(a,b);
}

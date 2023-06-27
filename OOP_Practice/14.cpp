#include<bits/stdc++.h>
using namespace std;

class cmplx
{
    double real, img;
    public:
    cmplx(){}
    cmplx (double real, double img)
    {
        this->real=real;
        this->img=img;
    }

    cmplx operator-(cmplx c2)
    {
        cmplx c3;
        c3.real=real-c2.real;
        c3.img=img-c2.img;
        return c3;
    }

    void show()
    {
        cout << real << " " << img << endl;
    }
};

int main()
{
    cmplx c1(34,45),c2(11,22),c3;
    c3=c1-c2;
    c3.show();
}
#include<bits/stdc++.h>
using namespace std;

class Mammals
{
    public:
    void show()
    {
        cout << "I am Mammals\n";
    }
};

class MarineAnimal
{
    public:
    void show()
    {
        cout << "I am marine animal\n";
    }
};

class BlueWhale: public Mammals, public MarineAnimal
{
    public:
    void show()
    {
        cout << "I am both mammals and marine animal\n";
    }
};

int main()
{
    BlueWhale a;
    a.Mammals::show();
}
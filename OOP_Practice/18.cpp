#include<bits/stdc++.h>
using namespace std;

class Fruit
{   
    protected:
    static int numberOfFruits;
    public:
    void show()
    {
        cout << "Total number of Fruits: " << numberOfFruits << endl;
    }
};

class Mangoes: public Fruit
{
    static int numberOfMangoes;
    public:
    Mangoes()
    {
        numberOfFruits++;
        numberOfMangoes++;
    }

    void show()
    {
        cout << "Total number of Mangoes: " << numberOfMangoes << endl;
    }
};

class Apples: public Fruit
{
    static int numberOfApples;
    public:
    Apples()
    {
        numberOfApples++;
        numberOfFruits++;
    }
    void show()
    {
        cout << "Total number of Apples: " << numberOfApples << endl;
    }

};

int Apples:: numberOfApples=0;
int Mangoes:: numberOfMangoes=0;
int Fruit:: numberOfFruits=0;

int main()
{
    Mangoes a,b;
    Apples c,d;
    
    a.show();
    c.show();
    a.Fruit::show();

}
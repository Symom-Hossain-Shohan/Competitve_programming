#include<bits/stdc++.h>
using namespace std;

class  Planet
{
    string planet_name;
    double distance,diameter;
    int number_of_moons;
    public:
    void get_planet_name()
    {
        cin >> planet_name ;
    }
    void get_number_of_moons()
    {
        cin >> number_of_moons;
    }
    void get_diameter()
    {
        cin >> diameter;
    }
    void get_distance()
    {
        cin >> distance;
    }

        
    void print_planet_name()
    {
        cout << planet_name << endl;
    }
    void print_number_of_moons()
    {
        cout << number_of_moons << endl;
    }
    void print_diameter()
    {
        cout << diameter << endl;
    }
    void print_distance()
    {
        cout << distance << endl;
    }

    friend void light(Planet a);
};

void light(Planet a)
{
    cout << a.distance*(1000000/186000)<< endl;
}

int main()
{
    cout << setprecision(2) << fixed ;
    int n;
    cin>>  n;
    Planet array[n];

    for(int i=0;i<n;i++)
    {
        array[i].get_planet_name();
        array[i].get_distance();
        array[i].get_diameter();
        array[i].get_number_of_moons();
        
    }
    for(int i=0;i<n;i++) light(array[i]);
}
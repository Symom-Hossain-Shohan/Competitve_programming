#include<bits/stdc++.h>

using namespace std;

class Student
{
    int roll;
    static int number_of_student;
    public:
    void get_number()
    {
        cin >> roll;
        number_of_student++;
    }
    void print_number()
    {
        cout << roll << endl;
    }
    static void getcount()
    {
        cout << number_of_student << endl;
    }
};

int Student:: number_of_student=0;

int main()
{
    Student a,b,c;
    a.get_number();
    b.get_number();
    c.get_number();
    Student::getcount();
}
#include<bits/stdc++.h>
using namespace std;

class Student
{
    string studentNo,studentName,dateOfBirth;
    int tarrifPoints;
    static int noOfStudents;
    public:
    Student()
    {
        studentNo="not known";
        studentName="not known";
        dateOfBirth="1st January 1995";
        tarrifPoints=20;
    }
    Student(string a,string b, string c, int t)
    {
        studentNo=a;
        studentName=b;
        dateOfBirth=c;
        tarrifPoints=t;
    }
    void display()
    {
        cout << studentNo << "      " << studentName << "      " << dateOfBirth << "      "<< tarrifPoints << endl;
    }


};

int main()
{
    vector<Student> v;
    while (1)
    {
        cout << "Press\n";
        cout << "   1. for creating student instance with unknown value.\n";
        cout << "   2. for creating student instance with known value\n";
        cout << "   3. to display.\n";
        cout << "   4. to exit.\n";

        int choice;
        cin >> choice;
        getchar();
        if(choice==4) break;
        else if(choice==3)
        {
            cout << "Student No       Name        Date of Birth          Tarrif Points\n";
            for(int i=0;i<(int ) v.size();i++)
            {
                v[i].display();
            }
        }
        else if(choice==2)
        {
            string a,b ,c;
            int d;
            getline(cin,a);
            getline(cin,b);
            getline(cin,c);
            cin >> d;
            Student obj(a,b,c,d);
            v.push_back(obj);
        }
        else 
        {
            Student obj;
            v.push_back(obj);
        }

    }
    
}
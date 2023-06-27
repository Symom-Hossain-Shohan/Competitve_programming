#include<bits/stdc++.h>
using namespace std;

class Student
{
    protected:
    int studentId;
    string studentName;
    public:
    void getData()
    {
        cin >> studentId;
        getchar();
        getline(cin,studentName);
    }

};

class Science: public Student
{
    int physics,chemistry,biology;
    public:
    void getData()
    {
        cin >> physics >> chemistry >> biology;
    }
    void show()
    {
        cout << studentId << endl;
        cout << studentName << endl;
        cout << physics << ' ' << chemistry << ' ' << biology << endl;
    }

};

class Arts: public Student
{
    int Engilsih, Economics,History;
    public :
    void getData()
    {
        cin >>Engilsih >> History >> Economics ;
    }

    void show()
    {
        cout << studentId << endl;
        cout << studentName << endl;
        cout << Engilsih << ' ' << History << ' ' << Economics << endl;
    }
};

int main()
{
    Science shawon;
    shawon.Student::getData();
    shawon.getData();
    shawon.show();
}

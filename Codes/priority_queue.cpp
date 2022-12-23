#include<bits/stdc++.h>
#include <queue>
#include <ratio>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

class Person
{
	public:
		string name; 
		int age; 
		Person(string n, int a)
		{
			name = n, age = a;  
		}
};

class PersonCompare
{
public:
	bool operator()(Person A, Person B)
	{
		return A.age < B.age;
	}
};

void solve()
{
    priority_queue<Person, vector<Person>, PersonCompare> pq; 
    ll n;
    cin >> n; 
    for(int i=1;i<=n;i++)
    {
    	string name; 
    	int age; 
    	cin >> name >> age;
    	Person p(name, age);
    	pq.push(p);
    }
    while (!pq.empty()) {
    	cout << pq.top().name <<endl;
    	pq.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}
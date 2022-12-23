#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, k, nn;
char a[3][3], p[6];


char f(int x, int y, int z){
	if (z==0){
		return a[x][y]; 
	}
	else {
		if ( a[x/p[z]][y/p[z]] == '*') return '*';
		else return f(x % p[z], y % p[z], z-1);
	}
}


int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> k; k--;
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin >> a[i][j];
	
	p[0] = 1;
	for (int i=1;i<=k;i++)
		p[i] = p[i-1] * n;
	nn = p[k] * n;
	
	
	for (int i=0;i<nn;i++){
		for (int j=0;j<nn;j++)
			cout << f(i, j, k);
		cout << endl;
	}
}
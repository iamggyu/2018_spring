#include<iostream>
#include<string>
#include<queue>
#include<vector>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;

int l, w;
int main() {
	double n, k, s, p;
	cin >> k >> n >> s >> p;
	double ans = ceil(n / s)*k / p;
	cout << ceil(ans);
	system("pause");
}


#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>   
#include <queue> 
using namespace std;

int minNum(string s) {
	const int n = s.size();
	vector<int> f(n+1,0);
	vector< vector<bool> > p(n,vector<bool>(n,false));
	//  fill_n(&p[0][0], n * n, false);
	//the worst case is cutting by each char
	for (int i = 0; i <= n; i++)
		f[i] = n - 1 - i; // 最后一个f[n]=-1

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
				p[i][j] = true;
				f[i] = min(f[i], f[j + 1] + 1);
			}
		}
	}
	return f[0];
}

void main(){
	string s="abbacc";
	int num=minNum(s);
	cout<< "输出为："<<num<<endl;
	system("pause");
}
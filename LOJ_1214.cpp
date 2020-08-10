#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MAX 1010
#define MOD 1000000007

using namespace std;

ll po(int n, int ex){ll res = 1; for(int i=1;i<=ex;i++) res*=n; return res;}

const int INF = INT_MAX/2;

vector<int> prime;


using namespace std;

int main(){

	int T = 1, cs = 0;
	scanf("%d", &T);
	while(T--)
	{
		string a;
		int b;
		cin >> a >> b;
		
		if (a[0] == '-') a[0] = '0';
		long long rem = 0;
		for (int j = 0; j < a.size(); j++)
			rem = ( 10*rem + (a[j] - '0') ) % b;
		
		if(rem == 0) cout << "Case " << ++cs << ": divisible\n";
		else cout << "Case " << ++cs << ": not divisible\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000005
#define PI 2*cos(0.0)
#define endl '\n'
using namespace std;

void solve()
{
  string a, b;
  cin >> a >> b;
///  cout << a << " " << b << endl;
  string S = b + '#' + a;
  int n = b.size(), len = S.size(), cnt = 0;
  vector<int> pi(len);

  for (int R = 1; R < len; R++)
  {
    int L = pi[R-1];
    while(L > 0 && S[L] != S[R])  L = pi[L-1];
    pi[R] = L + (S[L] == S[R]);

    if (pi[R] == n) cnt++;
  }
  cout << cnt;
  puts("");
}


int main() {
  int T, caseno = 0;
  scanf("%d", &T);
  while (T--)
  {
  	printf("Case %d: ", ++caseno);
  	solve();
  }
  return 0;
}



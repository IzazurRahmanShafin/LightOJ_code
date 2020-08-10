#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MAX 1010
#define MOD 1000000007

using namespace std;

ll po(int n, int ex){ll res = 1; for(int i=1;i<=ex;i++) res*=n; return res;}

const int INF = INT_MAX/2;

vector<int> prime;

void prime_factor()
{
	bool mark[MAX];
	memset(mark, true, sizeof mark);
	for (int i = 2; i*i <= MAX; i++)
		if(mark[i])	for (int j=i+i; j<=MAX; j=j+i) mark[j] = false;
	for (int i=2; i<=MAX; i++) if(mark[i]) prime.push_back(i);
}

int BFS(int s, int t)
{
	bool visited[MAX];
	int graphs[MAX];
	queue<int> Q;

	memset(visited, false, sizeof visited);
	Q.push(s);
	visited[s] = true;
	graphs[s] = 0;
	
	while(!Q.empty())
	{
		int q = Q.front();
		Q.pop();
		for(int u : prime)
		{
			int v;
			if(u < q && q%u == 0)
			{
				v = q + u;
				if (v <= t && !visited[v])
				{
					visited[v] = true;
					graphs[v] = graphs[q] + 1;
					Q.push(v);
					if(v == t) return graphs[v];
				}
			}
			else if(u > q) break;
		}
	}
	return -1;
}

int main()
{

    int T = 1, cs = 0;
	scanf("%d", &T);

	prime_factor();

    while(T--){
    	int s, t, res;
		scanf("%d %d", &s, &t);

		if (s == t)  printf("Case %d: 0\n", ++cs);
        else printf("Case %d: %d\n", ++cs, BFS(s, t));
    }
    return 0;
}

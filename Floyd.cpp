#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define INF int(1e9)
#define fs first
#define sc second
#define pii pair<int, int>

int n, m;
vector <vector<pair<int, int>>> g;
vector<vector<int>> d, nxt;

void Floyd()
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (d[i][k] < INF && d[k][j] < INF)
					if (d[i][k] + d[k][j] <= -INF)
						d[i][j] = -INF;
					else
					{
						if (d[i][j] > d[i][k] + d[k][j])
						{
							d[i][j] = d[i][k] + d[k][j];
							nxt[i][j] = nxt[i][k];
						}
					}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int t = 0; t < n; ++t)
				if (d[i][t] < INF && d[t][t] < 0 && d[t][j] < INF)
					d[i][j] = -INF;
}

int main()
{
	int s;
	cin >> n >> m;
	g.resize(n);
	d.resize(n, vector<int>(n, INF));
	nxt.resize(n, vector<int>(n, -1));
	for (int i = 0; i < m; i++)
	{
		int a, b, r;
		cin >> a >> b >> r;
		//a--; b--;
		g[a].push_back({ b, r });
		//g[b].push_back({ a, r });
		d[a][b] = r;
		//d[b][a] = r;
	}
	for (int i = 0; i < n; i++)
		d[i][i] = 0;
	Floyd();
	int s, f;
	cin >> s >> f;
	while (s != f)
	{
		cout << s << " ";
		s = nxt[s][f];
	}
	cout << f;
}

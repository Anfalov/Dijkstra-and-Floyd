#include <iostream>
#include <vector>

using namespace std;

#define INF int(1e9)
#define fs first
#define sc second

int n, m;
vector <vector<pair<int, int>>> g;
vector<int> d;
vector<char> u;

void Dijkstra(int s)
{
	d[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int mn = INF, mni = -1;
		for (int j = 0; j < n; j++)
			if (d[j] < mn && !u[j])
			{
				mn = d[j];
				mni = j;
			}
		if (mn == INF)
			break;
		u[mni] = 1;
		for (auto to : g[mni])
			if (d[to.fs] > d[mni] + to.sc)
				d[to.fs] = d[mni] + to.sc;
	}
}

int main()
{
	cin >> n >> m;
	g.resize(n);
	d.resize(n, INF);
	u.resize(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b, r;
		cin >> a >> b >> r;
		a--; b--;
		g[a].push_back({ b, r });
		g[b].push_back({ a, r });
	}
	int s, f;
	cin >> s >> f;
	Dijkstra(s - 1);
	if (d[f - 1] == INF)
		cout << -1;
	else
		cout << d[f - 1];
}

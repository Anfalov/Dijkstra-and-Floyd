#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define INF 2009000999
#define fs first
#define sc second

int n, m;
vector <vector<pair<int, int>>> g;
vector<int> d;
vector<char> u;

void Dijkstra(int s)
{
	set<pair<int, int>> mins;
	d[s] = 0;
	mins.insert({ 0, s });
	for (int i = 0; i < n; i++)
	{
		if (mins.empty())
			break;
		int v = mins.begin()->second;
		mins.erase(mins.begin());
		u[v] = 1;
		for (auto to : g[v])
		{
			if (d[to.fs] > d[v] + to.sc)
			{
				mins.erase({ d[to.fs], to.fs });
				d[to.fs] = d[v] + to.sc;
				mins.insert({ d[to.fs], to.fs });
			}
		}
	}
}

int main()
{
	int s;
	cin >> n >> m >> s;
	g.resize(n);
	d.resize(n, INF);
	u.resize(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b, r;
		cin >> a >> b >> r;
		//a--; b--;
		g[a].push_back({ b, r });
		g[b].push_back({ a, r });
	}
	Dijkstra(s);
	for (auto x : d)
		cout << x << " ";
}

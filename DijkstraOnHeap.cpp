#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define INF 2009000999
#define fs first
#define sc second
#define pii pair<int, int>

int n, m;
vector <vector<pair<int, int>>> g;
vector<int> d;
vector<char> u;

void Dijkstra(int s)
{
	//priority_queue<pair<int, int>> mins;
	priority_queue<pii, vector<pii>, greater<pii>> mins;
	d[s] = 0;
	mins.push({ 0, s });
	while (mins.size())
	{
		int v = mins.top().second;
		mins.pop();
		if (u[v])
			continue;
		u[v] = 1;
		for (auto to : g[v])
		{
			if (d[to.fs] > d[v] + to.sc)
			{
				d[to.fs] = d[v] + to.sc;
				//mins.push({ -d[to.fs], to.fs });
				mins.push({ d[to.fs], to.fs });
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

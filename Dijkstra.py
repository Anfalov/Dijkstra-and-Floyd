INF = int(1e9)

def Dijkstra(s):
	d[s] = 0
	for i in range(n):
		mn, mni = INF, -1
		for j in range(n):
			if d[j] < mn and not u[j]:
				mn, mni = d[j], j
		if mn == INF:
			break
		u[mni] = 1
		for to, r in g[mni]:
			if d[to] > d[mni] + r:
				d[to] = d[mni] + r
			

n, m = map(int, input().split())
g = [[] for i in range(n)]
d = [INF] * n
u = [0] * n

for i in range(m):
	a, b, r = map(int, input().split())
	a -= 1
	b -= 1
	g[a].append((b, r))
	g[b].append((a, r))
s, f = map(int, input().split())
Dijkstra(s - 1)
if d[f - 1] == INF:
	print(-1)
else:
	print(d[f - 1])

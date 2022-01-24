import heapq

INF = 2009000999

def Dijkstra(s):
	d[s] = 0
	heap = []
	heapq.heappush(heap, (0, s))
	while len(heap):
		dv, v = heapq.heappop(heap)
		if u[v]: #if d[v] != dv:
			continue
		u[v] = 1
		for to, r in g[v]:
			if d[to] > d[v] + r:
				d[to] = d[v] + r
				heapq.heappush(heap, (d[to], to))
				
			

n, m, s = map(int, input().split())
g = [[] for i in range(n)]
d = [INF] * n
u = [0] * n

for i in range(m):
	a, b, r = map(int, input().split())
	g[a].append((b, r))
	g[b].append((a, r))
Dijkstra(s)
print(*d)

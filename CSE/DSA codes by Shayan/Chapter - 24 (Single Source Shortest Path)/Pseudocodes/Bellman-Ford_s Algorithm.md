BELLMAN_FORD_SSSP(G, s):
1. make an array dis[1 :: n] and fill it with INF
2. dis[s] = 0
3. for i = 1 to n - 1
4.    for all edges E = (u, v, w) that belong to G.E
5.         if dis[u] != INF and dis[v] > dis[u] + w
6.              dis[v] = dis[u] + w
7. for all edges E = (u, v, w) that belong to G.E
8.     if dis[v] != dis[u] + w 
9.        return false
10. return true
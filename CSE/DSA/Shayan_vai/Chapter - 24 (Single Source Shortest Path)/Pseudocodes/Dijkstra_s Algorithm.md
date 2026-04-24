DIJKSTRA_SSSP(G, s):
1. make an array dis[1 :: n] and fill all its indices with INF
2. dis[s] = 0
3. Min Heap of pairs Q = {}
4. INSERT(Q, {s, 0})
5. while Q != {}
6.     pr <- EXTRACT_MIN(Q)
7.     node <- pr[0], wt <- pr[1]
8.     for all pairs p that belong to G.Adj[node]
9.         nei = p[0], w = p[1]
10.       if dis[nei] > wt + w
11.            dis[nei] = wt + w
12.            INSERT(Q, {nei, dis[nei]})
13. for i = 1 to n 
14.    print dis[i]
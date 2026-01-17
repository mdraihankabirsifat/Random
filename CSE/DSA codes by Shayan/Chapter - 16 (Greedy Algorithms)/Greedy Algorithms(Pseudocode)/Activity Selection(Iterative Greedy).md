ACTIVITY_SELECTION(s, f, n):
1. Sort 'a' according to the non descending order of finish times
2. Make a set S = {a[1]}
3. last <- 1
4. for i = 2 to n
5.    if a[i].s >= last.f
6.       S = S U {a[i]}
7.       last = i
8. print S
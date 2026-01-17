ACTIVITY_SELECTION(i, s, f, n):
1. Make a set S
2. last = NULL
3. if i == 1 
     4. S = S U {a[i]}
     5. last = i 
4. if i > n return
5. if i.s >= last.f  S = S U {a[i]}
6. ACTIVITY_SELECTION(i + 1, s, f, n)
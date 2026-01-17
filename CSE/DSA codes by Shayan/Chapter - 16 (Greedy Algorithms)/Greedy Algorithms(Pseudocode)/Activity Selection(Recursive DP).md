ACTIVITY_SELECTION_RDP(s, f, n):
1. let c[0 :: n + 1] and act[0 :: n + 1] be two tables
2. fill both of the tables with -1
3. REC(0, n + 1, c, act, n)
4. PRINT_ACTIVITIES(0, n + 1, act)

REC(i, j, c, act, n):
1. if j <= i + 1   return c[i, j] = 0
2. if c[i, j] != -1   return c[i, j]
3. c[i, j] <- 0
4. for k = i + 1 to j - 1
5.    if(a[k].s > a[i].f && a[k].f < a[j].s)
6.        ans <- f(i, k, c, act, n)
7.        if ans > c[i, j]
8.           c[i, j] = ans
9.           act[i, j] = k
10. return c[i, j]

PRINT_ACTIVITIES(i, j, act):
1. k <- act[i, j]
2. if k == -1 return;
3. PRINT_ACTIVITIES(i, k, act)
4. print a[k].s and a[k].f
5. PRINT_ACTIVITIES(k, j, act)


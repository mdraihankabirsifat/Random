Notes : 'a' stores all the activities. 'a' is sorted in non decreasing order of the finish time of the activities.
ACTIVITY_SELECTION_IDP(s, f, n):
1. let c[0 :: n + 1] and act[0 :: n + 1] be two tables.
2. Fill table c[0 :: n + 1] with 0 and table act[0 :: n + 1] with -1.
3. for i = n + 1 to 0
4.    for j = i + 2 to n + 1
5.        for k = i + 1 to j - 1
6.            if(a[k].s > a[i].f && a[k].f < a[j].s)
7.                  ans <- c[i, k] + c[k, j] + 1
8.                      if(ans > c[i, j])
9.                         c[i, j] = ans
10.                       act[i, j] = k;
11. print "A maximum size of mutually compatible activities :" c[0 :: n + 1]
12. PRINT_ACTIVITIES(0, n + 1, act)

PRINT_ACTIVITIES(i, j, act): 
   1. k <- act[i, j]
   2. if k = -1   return;
   3. PRINT_ACTIVITIES(i, k, act)
   4. print a[k].s and a[k].f
   5. PRINT_ACTIVITIES(k, j, act)
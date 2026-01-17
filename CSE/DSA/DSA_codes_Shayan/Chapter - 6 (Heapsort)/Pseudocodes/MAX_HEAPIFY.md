// Recursive:
MAX_HEAPIFY(A, i):
1. let n be the size of the array A
2. l = left(i), r = right(i)
3. if l > n return
4. if r > n  mx = l
5. else
6.    if A[l] > A[r]  mx = l
7.    else  mx = r
8. if A[i] >= A[mx]  return
9. swap(A[i], A[mx])
10. MAX_HEAPIFY(A, mx)

// Iterative:
MAX_HEAPIFY(A, i):
1. let n be the size of the array A
2. l = left(i), r = right(i)
3. while l <= n
4.    if r > n  mx = l
5.    else
6.      if A[l] > A[r] mx = l
7.      else mx = r
8.    if A[i] >= A[mx]  break
9.    swap(A[i], A[mx])
10.  i = mx
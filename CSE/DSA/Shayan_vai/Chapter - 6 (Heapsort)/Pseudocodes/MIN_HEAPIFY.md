// Recursive:
MIN_HEAPIFY(A, i):
1. let n be the size of the array A
2. l = left(i), r = right(i)
3. if l > n return
4. if r > n  mn = l
5. else
6.    if A[l] < A[r]  mn = l
7.    else  mn = r
8. if A[i] <= A[mn]  return
9. swap(A[i], A[mn])
10. MIN_HEAPIFY(A, mn)

// Iterative:
MIN_HEAPIFY(A, i):
1. let n be the size of the array A
2. l = left(i), r = right(i)
3. while l <= n
4.    if r > n  mn = l
5.    else
6.      if A[l] < A[r] mn = l
7.      else mn = r
8.    if A[i] <= A[mn]  break
9.    swap(A[i], A[mn])
10.  i = mn
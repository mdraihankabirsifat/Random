PERCOLATE_UP(A, i):
1. while i > 1 and A[i] > A[parent(i)]
2.    swap(A[i], A[parent(i)])
3.    i = parent(i)
// For max heap
HEAP_DELETE(A, i): 
1. if i == A.heap_size
2.    A.heap_size = A.heap_size - 1
3. old_key = A[i]
4. swap(A[i], A[A.heap_size])
5. A.heap_size = A.heap_size - 1
6. if A[i] > old_key
7.   PERCOLATE_UP(A, i)
8. else
9.   MAX_HEAPIFY(A, i)
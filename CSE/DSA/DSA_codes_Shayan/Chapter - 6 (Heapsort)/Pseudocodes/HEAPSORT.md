HEAPSORT(A):
1. BUILD_MAX_HEAP(A)
2. for i = n to 2
3. swap(A[1], A[n])
4. A.heap_size = A.heap_size - 1
5. MAX_HEAPIFY(A, 1)
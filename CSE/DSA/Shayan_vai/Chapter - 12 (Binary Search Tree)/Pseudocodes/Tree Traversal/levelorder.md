LEVELORDER(root):
1. Define a queue Q
2. Define a Linked List l
3. PUSH(Q, root)
4. while Q.size != 0
5.    node = Q.front
6.    Q.pop
7.    INSERT(l, node->key)
8.    for all vertices v belonging to G.adj[node]
9.        PUSH(Q, v)
10. print(l)
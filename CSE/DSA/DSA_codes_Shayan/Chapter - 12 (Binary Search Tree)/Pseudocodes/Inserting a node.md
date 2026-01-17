TREE_INSERT(T, node):
1. y = NULL
2. x = T->root
3. if x == NULL
4.   root = node
5.   node->parent = NULL
6.   return
7. while x != NULL
8.    y = x
9.    if(node->key < x->key)
10.      x = x->left
11.    else
12.      x = x->right
13. if y == NULL
14.      T->root = node
15. else if node->key < y->key
16.    y->left = node
17. else
18.    y->right = node
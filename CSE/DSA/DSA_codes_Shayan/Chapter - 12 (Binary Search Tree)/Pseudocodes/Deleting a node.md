TRANSPLANT(T, u, v):
1. if u->parent == NULL
2.   T->root = v
3. else if u->parent->left == u
4.   u->parent->left = v
5. else
6.   u->parent->right = v
7. if v != NULL
8.   v->parent = u->parent

TREE_DELETE(T, z):
1. if z == NULL
2. return
3. if T->root == NULL 
4. return
5. if z->left == NULL
6.   TRANSPLANT(T, z, z->right)
7. else if z->right == NULL
8.    TRANSPLANT(T, z, z->left)
9. else 
10.   y = TREE_MINIMUM(z->right)
11.   if y != z->right
12.      TRANSPLANT(T, y, y->right)
13.      y->right = z->right
14.      y->right->parent = y
15.   TRANSPLANT(T, z, y)
16.   y->left = z->left
17.   y->left->parent = y
18. delete z
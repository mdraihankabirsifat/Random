// Recursive:
PREORDER(root):
1. if root == NULL
2. return
3. print(root->key)
4. PREORDER(root->left)
5. PREORDER(root->right)

// Iterative:
PREORDER(root):
1. Define a stack st
2. INSERT(st, root)
3. while st.size != 0
4.     node = st.top
5.     st.pop
6.     print(node->key)
7.     if node->right != NULL
8.        INSERT(node->right)
9.     if node->left != NULL
10.        INSERT(node->left)

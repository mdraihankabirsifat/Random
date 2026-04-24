// Recursive:
POSTORDER(root):
1. if root == NULL 
2. return
3. POSTORDER(root->left)
4. POSTORDER(root->right)
5. print(root->key)

// Iterative:
POSTORDER(root):
1. Define a stack st
2. Define a linked list l
3. INSERT(st, root)
4. while st.size != 0
5.    node = st.top
6.    st.pop
7.    INSERT(l, node->key)
8.    INSERT(st, node->left)
9.    INSERT(st, node->right)
10. REVERSE(l)
11. print(l)
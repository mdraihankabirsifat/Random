// Recursive:
INORDER(root):
1. if root == NULL
2. return
3. INORDER(root->left)
4. print(root->key)
5. INORDER(root->right)

// Iterative:
INORDER(root):
1. define stack st
2. node = root
3. while true
4.   if node != NULL
5.     st.push(node)
6.     node = node->left
7.   else
8.     if st.empty() break
9.      node = st.top()
10.    st.pop()
11.    print node->key
12.    node = node->right

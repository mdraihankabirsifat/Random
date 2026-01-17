// Recursive:
TREE_SEARCH(node, value):
1. if node == NULL or node->key == value
2. return node
3. if value < node->key
4. return TREE_SEARCH(node->left, value)
5. else
6. return TREE_SEARCH(node->right, value)

// Iterative:
TREE_SEARCH(node, value):
1. while node != NULL
2.      if value == node->key
3.         return node
4.      else if value < node->key
5.         node = node->left
6.       else
7.          node = node->right
8. return node
TREE_SUCCESSOR(node):
1. if node->right != NULL
2.    return TREE_MINIMUM(node->right)
3. else
4.    y = node->parent
5.    while y != NULL and y->right == node
6.       node = y
7.       y = y->parent
8.    return y

TREE_PREDECESSOR(node):
1. if node->left != NULL
2.    return TREE_MAXIMUM(node->left)
3. else 
4.    y = node->parent
5.    while y != NULL and y->left == node
6.       node = y
7.       y = y->parent
8.    return y
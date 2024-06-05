#include "binary_trees.h"

/**
* binary_tree_sibling - Finds the sibling of a node
*
* @node: Pointer to the root node of the tree
*
* Return: A pointer to the sibling node
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If the node or its parent is NULL, there's no sibling. */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/**
	 * If the node is the left child,
	 * return the right child of the parent.
	 */
	if (node->parent->left == node)
		return (node->parent->right);

	/**
	 * This means the node is the left child,
	 * return the right child of the parent.
	 */
	return (node->parent->left);
}

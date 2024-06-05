#include "binary_trees.h"

/**
* binary_tree_uncle - Finds the uncle of a node
*
* @node: Pointer to the root node of the tree
*
* Return: A pointer to the uncle node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Return the sibling of the parent which mean the uncle */
	return (binary_tree_sibling(node->parent));
}

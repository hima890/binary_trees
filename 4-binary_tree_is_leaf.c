#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check of the parent node is valid node */
	if (node == NULL)
	{
		return (0);
	}
	/* Check of the there is a right and left node for this node*/
	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	/* Return 1 if the node has no childs(Leaf)*/
	return (0);
}

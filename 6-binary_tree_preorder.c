#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary tree using pre-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check the tree root node and the function */
	if (tree == NULL || func == NULL)
	{
		return;
	}
	/* Apllay the function on the node number value */
	func(tree->n);
	/* Recursively traverse left and right subtrees */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

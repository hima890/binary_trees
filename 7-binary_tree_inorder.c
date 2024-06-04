#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree using in-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check the tree root node and the function */
	if (tree == NULL || func == NULL)
	{
		return;
	}

	/* Recursively traverse left subtrees */
	binary_tree_inorder(tree->left, func);

	/* Apllay the function on the node number value */
	func(tree->n);

	/* Recursively traverse right subtrees */
	binary_tree_inorder(tree->right, func);
}

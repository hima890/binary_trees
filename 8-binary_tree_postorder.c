#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_postorder - Postorder a binary tree using postorder traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check the tree root node and the function */
	if (tree == NULL || func == NULL)
	{
		return;
	}
	/* Recursively traverse left and right subtrees */
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	/* Apllay the function on the node number value */
	func(tree->n);
}

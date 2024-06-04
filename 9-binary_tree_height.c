#include "binary_trees.h"
#include <stdio.h>

/**
* binary_tree_height -  Measures the height of a binary tree
*
* @tree: Pointer to the root node of the tree
*
* Return: The height of a binary tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Recursively calculate the height of the left and right subtrees */
	size_t left_height = 0;
	size_t right_height = 0;

	/* Calculate height of left subtree if it exists */
	if (tree->left)
	{
		left_height = 1 + binary_tree_height(tree->left);
	}

	/* Calculate height of right subtree if it exists */
	if (tree->right)
	{
		right_height = 1 + binary_tree_height(tree->right);
	}

	/* Return the greater of the two heights */
	return ((left_height > right_height) ? left_height : right_height);
}

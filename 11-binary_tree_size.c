#include "binary_trees.h"
#include <stdio.h>

/**
* binary_tree_size -  Measures the size of a binary tree
*
* @tree: Pointer to the root node of the tree
*
* Return: The size of a binary tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Recursively calculate the size of the left and right subtrees */
	size_t left_size = binary_tree_size(tree->left);
	size_t right_size = binary_tree_size(tree->right);

	return (1 + (left_size + right_size));
}

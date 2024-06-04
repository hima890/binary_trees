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
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	/**
	* Return the maximum height between left and right subtrees
	* plus 1 for the current node
	*/
	return (1 + ((left_height > right_height) ? left_height : right_height));
}

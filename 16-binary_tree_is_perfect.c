#include "binary_trees.h"
#include <math.h>

/**
* binary_tree_is_perfect -  Checks if a binary tree is perfect
*
* @tree: Pointer to the root node of the tree
*
* Return: 1 if a binary tree is perfect otherwise 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, per_formula;

	/* If the tree is NULL, it's not perfect. */
	if (tree == NULL)
		return (0);

	/* Calculate the height and size of the tree. */
	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	/* Check if the tree satisfies the perfect tree formula. */
	per_formula = pow(2, height + 1) - 1;
	return (per_formula == size);
}

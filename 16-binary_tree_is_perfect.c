#include "binary_trees.h"
#include <math.h>
/**
 *pow - returns the value of x raised to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */

int powr(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * powr(x, y - 1));

}

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

/**
* binary_tree_size -  Measures the size of a binary tree
*
* @tree: Pointer to the root node of the tree
*
* Return: The size of a binary tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}

#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree. If tree is NULL, return 0.
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree (BST).
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowed value.
 * @max: Maximum allowed value.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
	is_bst(tree->right, tree->n, max));
}

/**
 * is_balanced - Checks if a binary tree is balanced.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is balanced, and 0 otherwise.
 */
int is_balanced(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX) && is_balanced(tree));
}

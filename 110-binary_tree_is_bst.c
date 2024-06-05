#include "binary_trees.h"

/**
 * inorder_traversal - Perform in-order traversal and check BST.
 * @tree: Pointer to the root node of the tree to check.
 * @prev: Pointer to the previous node value.
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise.
 */
int inorder_traversal(const binary_tree_t *tree, const binary_tree_t **prev)
{
	if (tree == NULL)
		return (1);

	/* Check left subtree*/
	if (!inorder_traversal(tree->left, prev))
		return (0);

	/* Current node must be greater than the previous node*/
	if (*prev != NULL && tree->n <= (*prev)->n)
		return (0);

	/* Update previous node to current node*/
	*prev = tree;

	/* Check right subtree*/
	return (inorder_traversal(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *prev = NULL;

	/*An empty tree is not considered a BST by this implementation*/
	if (tree == NULL)
		return (0);

	return (inorder_traversal(tree, &prev));
}

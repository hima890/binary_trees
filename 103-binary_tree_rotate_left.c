#include "binary_trees.h"

/**
* binary_tree_rotate_left - Performs a left-rotation on a binary tree.
* @tree: Pointer to the root node of the tree to rotate.
*
* Return: Pointer to the new root node after rotation.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* If the tree is NULL or if the right child of the tree is NULL,*/
	/* we cannot perform a left rotation.*/
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/* Set new_root to the right child of the current root.*/
	new_root = tree->right;

	/*The left child of the new root becomes the right child of the root.*/
	tree->right = new_root->left;

	/* If the new root's left child is not NULL,*/
	/* set its parent to the current root.*/
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	/* Set the left child of the new root to the current root.*/
	new_root->left = tree;

	/* Update the parent of the new root to be the parent of the current root.*/
	new_root->parent = tree->parent;

	/* Set the parent of the current root to the new root.*/
	tree->parent = new_root;

	/* Return the new root node.*/
	return (new_root);
}

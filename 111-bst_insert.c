#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert into the tree
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *parent;
	bst_t *new_node;

	if (tree == NULL)
		return (NULL);

	current = *tree;
	parent = NULL;

	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL); /* Value already exists in the tree */
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent == NULL)
		*tree = new_node; /* Tree was empty */
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

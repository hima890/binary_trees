#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	/* Check if the tree pointer is not NULL*/
	if (tree != NULL)
	{
		curr = *tree;

		/* If the tree is empty, create a new root node*/
		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		/*
		* If the value to be inserted is less than,
		* the current node's value, insert in the left subtree
		**/
		if (value < curr->n)
		{
			// If the left child exists, recursively insert into the left subtree
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			// Otherwise, create a new node and set it as the left child
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);		   // Return NULL if node creation fails
			return (curr->left = new); // Set the new node as the left child and return it
		}

		// If the value to be inserted is greater than the current node's value,
		// insert in the right subtree
		if (value > curr->n)
		{
			// If the right child exists, recursively insert into the right subtree
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			/* Otherwise, create a new node and set it as the right child*/
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}

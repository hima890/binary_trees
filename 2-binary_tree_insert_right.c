#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check of the parent node is valid node */
	if (parent == NULL)
	{
		return (NULL);
	}
	/* Create the new node */
	new_node = malloc(sizeof(binary_tree_t));
	/* Check of the allcoted memory is valid */
	if (new_node == NULL)
	{
		return (NULL);
	}
	/* Set the new node values */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	/* If the parent node has right child note replace it with the new node */
	if (parent->right != NULL)
	{
		/* The old parent right node set to be the new node right child */
		new_node->right = parent->right;
		/* The new node set to be the parent new right node */
		new_node->right->parent = new_node;
	}
	/**
	 * If the parent node dont have a right node set
	 *  the new node as parent new right node
	*/
	parent->right = new_node;

	return (new_node);
}

#include "binary_trees.h"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
*
* @first: Pointer to the first node
*
* @second: Pointer to the second node
*
* Return: A pointer to the lowest common ancestor
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	/* If either node is NULL, there's no common ancestor. */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Calculate the depths of both nodes. */
	size_t depth_first = binary_tree_depth(first);
	size_t depth_second = binary_tree_depth(second);

	/* Adjust the deeper node's position to match the other node's depth. */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	/* Traverse up the tree until a common ancestor is found. */
	while (first && second)
	{
		if (first == second)
			return (first);
		first = first->parent;
		second = second->parent;
	}

	return (first);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Node to calculate the depth of.
 *
 * Return: Depth of the node, or 0 if the tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

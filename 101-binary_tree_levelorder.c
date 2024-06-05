#include "binary_trees.h"

void currentLevel(const binary_tree_t *root, int level, void (*func)(int));

/**
* binary_tree_levelorder - Measures the depth of a node in a binary tree.
* @tree: Pointer to the node to measure the depth.
*
* @func: Pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree == NULL || func == NULL)
		return;

	size_t height = binary_tree_height(tree);

	for (size_t i = 1; i <= height + 1; i++)
		currentLevel(tree, i, func);
}

/**
* currentLevel - Pass nodes to fun at a current level
* @root: A pointer to the root node of the tree to measure the height.
* @level: Current level
* @func: Pointer to a function to call for each node
*
* Return: If tree is NULL, your function must return 0, else return height.
*/
void currentLevel(const binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
		return;

	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		currentLevel(root->left, level - 1, func);
		currentLevel(root->right, level - 1, func);
	}
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

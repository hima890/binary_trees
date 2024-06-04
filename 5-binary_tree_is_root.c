#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_is_root - Checks if a given node is a root
*
* @node: Pointer to the node to be checked
*
* Return: 1 if node is a root, otherwise 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{

	/* If there is no tree or parent return 0 */
	if (node == NULL || node->parent != NULL)
	{
		return (0);
	}
	else
		/* if the root return 1 */
		return (1);
}

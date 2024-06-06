#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_queue - Creates a new, empty queue
 *
 * Return: Pointer to the newly created queue, or NULL on failure
 *
 * Description: This function allocates and initializes a new empty queue
 * for use in level-order traversal of a binary tree.
 */
queue_t *create_queue(void)
{
	queue_t *q = malloc(sizeof(queue_t));

	if (!q)
	{
		return (NULL);
	}
	q->front = q->rear = NULL;
	return (q);
}

/**
 * enqueue - Adds a node to the end of the queue
 * @q: Pointer to the queue
 * @node: Pointer to the binary tree node to add to the queue
 *
 * Description: This function creates a new queue node containing the
 * given binary tree node and adds it to the end of the queue.
 */
void enqueue(queue_t *q, binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (!new_node)
	{
		return;
	}
	new_node->node = node;
	new_node->next = NULL;
	if (q->rear)
	{
		q->rear->next = new_node;
	}

	q->rear = new_node;
	if (!q->front)
	{
		q->front = new_node;
	}
}

/**
 * dequeue - Removes and returns the node from the front of the queue
 * @q: Pointer to the queue
 *
 * Return: Pointer to the binary tree node at the front of the queue,
 * or NULL if the queue is empty
 *
 * Description: This function removes the node from the front of the queue
 * and returns the binary tree node contained in it.
 */
binary_tree_t *dequeue(queue_t *q)
{
	if (!q->front)
	{
		return (NULL);
	}
	queue_node_t *temp = q->front;
	binary_tree_t *node = temp->node;

	q->front = q->front->next;
	if (!q->front)
	{
		q->rear = NULL;
	}
	free(temp);
	return (node);
}

/**
 * free_queue - Frees all nodes in the queue
 * @q: Pointer to the queue
 *
 * Description: This function deallocates all nodes in the queue,
 * effectively freeing all memory used by the queue.
 */
void free_queue(queue_t *q)
{
	while (q->front)
		dequeue(q);
	free(q);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The
 * value in the node must be passed as a parameter to this function.
 *
 * Description: This function traverses a binary tree using
 * level-order traversal.
 * For each node visited, the specified function is called
 * with the node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}
	queue_t *q = create_queue();

	if (!q)
	{
		return;
	}
	enqueue(q, (binary_tree_t *)tree);

	while (q->front)
	{
		binary_tree_t *current = dequeue(q);

		func(current->n);

		if (current->left)
			enqueue(q, current->left);
		if (current->right)
			enqueue(q, current->right);
	}

	free_queue(q);
}

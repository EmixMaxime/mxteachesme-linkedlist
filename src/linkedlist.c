#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "os/unix/mx_alloc.h"


Node *linkedlist_create_node(int data)
{
	Node *new;

	new = mx_malloc(sizeof(*new));

	new->data = data;
	new->next = NULL;

	return new;
}

List *linkedlist_init()
{
	List *list;
	Node *node;

	list 	= mx_malloc(sizeof(*list));
	node = mx_malloc(sizeof(*node));

	node->data = 0;
	node->next = NULL;
	list->head = node;

	return list;
}

void linkedlist_insert_head(List *list, Node *el)
{
	if (list->head == NULL) {
		list->head = el;
	}
	else {
		el->next = list->head;
		list->head = el;

	}
}

void linkedlist_insert_tail(List *list, Node *el)
{
	Node *last;

	last = linkedlist_get_tail(list);

	if (last == NULL) {
		list->head = el;
	}
	else {
		last->next = el;
	}
}

void linkedlist_print(List *list)
{
	Node *node;
	node = list->head;

	while (node != NULL)
	{
		printf("%d -> ", node->data);
		node = node->next;
	}

	printf("NULL\n");
}

Node *linkedlist_get_tail(List *list)
{
	Node *node;

	node = list->head;

	while (node->next != NULL)
	{
		node = node->next;
	}

	return node;
}

/**
 * Je parcours la liste jusqu'à ce que
 * la valeur est > à data
 * Ça veut dire que je dois prendre l'élément juste avant
 * le modifier pour mettre next à Node (new)
 * Ne pas oublier de mettre à new Node le suivant à l'élément en cours
 */
void linkedlist_sorted_insert(List *list, Node *el)
{
	Node *current_node;
	Node *previous_element;
	Node *new;
	int data;

	data = el->data;
	current_node = list->head;
	previous_element = current_node;

	int find = 0;
	int n = 0;

	while (current_node != NULL && find == 0)
	{
		if (data < current_node->data)
		{
			find = 1;
		}
		else
		{
			n++;
			previous_element = current_node;
			current_node = current_node->next;
		}
	}

	new = linkedlist_create_node(data);

	if (n == 0)
	{
		linkedlist_insert_head(list, new);
		return;
	}

	new->next = current_node;
	previous_element->next = new;
}

bool linkedlist_is_sorted(List *list)
{
	Node *current_node;
	Node *previous_node;

	int is_sorted = 1;

	current_node = list->head;
	previous_node = current_node;

	while (current_node != NULL && is_sorted == 1)
	{
		if (previous_node->data > current_node->data)
		{
			is_sorted = 0;
		}
		else
		{
			previous_node = current_node;
			current_node = current_node->next;
		}
	}

	return is_sorted;
}

void linkedlist_destroy(List *list)
{
	Node *to_destroy;
	Node *el;

	to_destroy = list->head;
	el = list->head->next;

	while (to_destroy != NULL)
	{
		free(to_destroy);
		if (el->next != NULL)
		{
			to_destroy = el;
			el = el->next;
		}
		else
		{
			to_destroy = NULL;
		}
	}
}

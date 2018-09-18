#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"

void main()
{
	printf("hello world");
	List *list = linkedlist_init();
	list->head->data = 999;

	linkedlist_sorted_insert(list, linkedlist_create_node(6));
	linkedlist_sorted_insert(list, linkedlist_create_node(7));
	linkedlist_sorted_insert(list, linkedlist_create_node(4));
	linkedlist_sorted_insert(list, linkedlist_create_node(1));
	linkedlist_sorted_insert(list, linkedlist_create_node(55));

	linkedlist_insert_head(list, linkedlist_create_node(20));
	linkedlist_insert_tail(list, linkedlist_create_node(22));

	linkedlist_print(list);

	Node *last = linkedlist_get_tail(list);
	printf("Last element data  = %d \n", last->data);

	linkedlist_destroy(list);
}

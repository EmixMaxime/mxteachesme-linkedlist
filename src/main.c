#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "helpers.h"

void test_sorted_insert() {
	List *list = linkedlist_init();
	list->head->data = 50;

	linkedlist_sorted_insert(list, linkedlist_create_node(6));
	linkedlist_print(list);

	linkedlist_sorted_insert(list, linkedlist_create_node(7));
	linkedlist_print(list);

	linkedlist_sorted_insert(list, linkedlist_create_node(4));
	linkedlist_print(list);

	linkedlist_sorted_insert(list, linkedlist_create_node(200));
	linkedlist_print(list);


	assert(list->tail->data == 200, "Bad tail.");

	assert(1, "test_sorted_insert OK.");
}

void main()
{
	test_sorted_insert();

	// List *list = linkedlist_init();
	// list->head->data = 100;

	// linkedlist_sorted_insert(list, linkedlist_create_node(6));
	// linkedlist_sorted_insert(list, linkedlist_create_node(7));
	// linkedlist_sorted_insert(list, linkedlist_create_node(4));
	// linkedlist_sorted_insert(list, linkedlist_create_node(1));
	// linkedlist_sorted_insert(list, linkedlist_create_node(55));
	// linkedlist_sorted_insert(list, linkedlist_create_node(200));

	// // linkedlist_insert_head(list, linkedlist_create_node(20));
	// // linkedlist_insert_tail(list, linkedlist_create_node(22));
	// // linkedlist_insert_tail(list, linkedlist_create_node(44));

	// linkedlist_print(list);

	// printf("Head  = %d, tail = %d \n", list->head->data, list->tail->data);

	// linkedlist_destroy(list);
}

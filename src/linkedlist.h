#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;
struct Node
{
	int data;
	Node *next;
};

typedef struct List List;
struct List
{
	Node *head;
};

/**
 * Définition des prototypes
 */

Node *linkedlist_create_node(int data);
void linkedlist_insert_head(List *list, Node *el);
void linkedlist_insert_tail(List *list, Node *el);
void linkedlist_print(List *list);

Node *linkedlist_get_tail(List *list);

bool linkedlist_is_sorted(List *list);
void linkedlist_sorted_insert(List *list, Node *el);

List *linkedlist_init();
void linkedlist_destroy(List *list);

#endif

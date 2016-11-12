//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_SINGLYLINKEDLIST_H
#define LIB_SINGLYLINKEDLIST_H

#include "node.h"
#include "list.h"

typedef struct singly_linked_list {
	Node* head;
	Node **head_address;
	int size;
} singly_linked_list;

// * Create the list
singly_linked_list* create_singly_ll();

// * Insert nodes
void sll_insert_front(singly_linked_list *sll, int value);
void sll_insert_back(singly_linked_list *sll, int value);
void sll_insert_back_recursive(singly_linked_list *sll, int value);

// * Remove nodes
void sll_remove_by_name(singly_linked_list *sll, char* name);
void sll_remove_by_value(singly_linked_list *sll, int value);

// * Delete list
void delete_sll(singly_linked_list *sll);

// * Utilities

// ** Change node name
void sll_set_name(Node *head, int value, char* name);

#endif //LIB_SINGLYLINKEDLIST_H

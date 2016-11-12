//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_CIRCULARLINKEDLIST_H
#define LIB_CIRCULARLINKEDLIST_H

#include "list.h"

typedef struct circular_linked_list {
	Node* head;
	Node **head_address;
	int size;
} circular_linked_list;

// * Create the list
circular_linked_list* create_circular_ll();

// * Insert nodes
void cll_insert_front(circular_linked_list *cll, int value);
void cll_insert_back(circular_linked_list *cll, int value);
void cll_insert_back_name(circular_linked_list *cll, int value, char* name);
void cll_insert_back_recursive(circular_linked_list *cll, int value);

// * Remove nodes
void cll_remove_by_name(circular_linked_list *cll, char* name);
void cll_remove_by_value(circular_linked_list *cll, int value);

// * Delete list
void delete_cll(circular_linked_list *cll);

// * Utilities

// ** Change node name
void cll_set_name(Node *head, int value, char* name);

// ** Print circular list
void print_cll(Node *head);

// ** Lookup
Node* cll_lookup_name(circular_linked_list* cll, char* name);
Node* cll_lookup_value(circular_linked_list* cll, int value);

#endif //LIB_CIRCULARLINKEDLIST_H

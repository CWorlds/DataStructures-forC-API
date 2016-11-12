//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_DLL_H
#define LIB_DLL_H

#include "list.h"

typedef struct doubly_linked_list {
	Node* head;
	Node **head_address;
	int size;
} doubly_linked_list;

// * Create the list
doubly_linked_list* create_doubly_ll();

// * Insert nodes
void dll_insert_front(doubly_linked_list *dll, int value);
void dll_insert_back(doubly_linked_list *dll, int value);
void dll_insert_back_name(doubly_linked_list *dll, int value, char* name);
void dll_insert_back_recursive(doubly_linked_list *dll, int value);

// * Remove nodes
void dll_remove_by_name(doubly_linked_list *dll, char* name);
void dll_remove_by_value(doubly_linked_list *dll, int value);

// * Delete list
void delete_dll(doubly_linked_list *dll);

// * Utilities

// ** Change node name
void dll_set_name(Node *head, int value, char* name);

#endif
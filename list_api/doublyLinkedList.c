//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#include "doublyLinkedList.h"

// * Create the list
doubly_linked_list* create_doubly_ll() {
	doubly_linked_list* new_dll = malloc(sizeof(doubly_linked_list));

	new_dll->head = NULL;
	new_dll->head_address = &new_dll->head;
	new_dll->size = 0;

	return new_dll;
}

// * Insert nodes
void dll_insert_front(doubly_linked_list *dll, int value) {
	Node* new_node = createNode(value);

	if (new_node) {
		insert_front_two_way(dll->head_address, new_node);
		dll->size++;
	}
}

void dll_insert_back(doubly_linked_list *dll, int value) {
	Node* new_node = createNode(value);

	if (new_node) {
		insert_back_two_way(dll->head_address, new_node);
		dll->size++;
	}
}

void dll_insert_back_name(doubly_linked_list *dll, int value, char* name) {
	Node* new_node = createNode(value);

	if (new_node) {
		insert_back_two_way(dll->head_address, new_node);
		dll->size++;
	}

	dll_set_name(dll->head, value, name);
}

void dll_insert_back_recursive(doubly_linked_list *dll, int value) {
	Node* new_node = createNode(value);

	if (new_node) {
		insert_back_recursive_two_way(dll->head_address, new_node);
	}
}

// * Remove nodes
void dll_remove_by_name(doubly_linked_list *dll, char* name) {
	remove_by_name_two_way(dll->head_address, name);
}

void dll_remove_by_value(doubly_linked_list *dll, int value) {
	remove_by_value_two_way(dll->head_address, value);
}

// * Delete list
void delete_dll(doubly_linked_list *dll) {

	if (dll != NULL) {
		delete_list_two_way(dll->head_address);

		dll->head = NULL;
		dll->head_address = NULL;

		free(dll);
	}
}

// * Utilities

// ** Change node name
void dll_set_name(Node *head, int value, char* name) {
	Node *temp = lookup_number(head, value);
	setName(temp, name);
}
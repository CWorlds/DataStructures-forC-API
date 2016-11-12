//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#include "singly_linked_list.h"

// * Create the list

singly_linked_list* create_singly_ll() {
	singly_linked_list* new_sll = malloc(sizeof(singly_linked_list));

	new_sll->head = NULL;
	new_sll->head_address = &new_sll->head;
	new_sll->size = 0;

	return new_sll;
}

// * Insert nodes

void sll_insert_front(singly_linked_list *sll, int value) {

	Node *new_node = createNode(value);

	if (new_node) {
		insert_front_one_way(sll->head_address, new_node);
		sll->size++;
	}
}

void sll_insert_back(singly_linked_list *sll, int value) {
	Node *new_node = createNode(value);

	if (new_node) {
		insert_back_one_way(sll->head_address,  new_node);
		sll->size++;
	}
}

void sll_insert_back_recursive(singly_linked_list *sll, int value) {
	Node *new_node = createNode(value);

	if (new_node) {
		insert_back_recursive_one_way(sll->head_address,  new_node);
		sll->size++;
	}
}

// * Remove nodes

void sll_remove_by_name(singly_linked_list *sll, char* name) {
	remove_by_name_one_way(sll->head_address, name);
}

void sll_remove_by_value(singly_linked_list *sll, int value) {
	remove_by_value_one_way(sll->head_address, value);
}

// * Delete list

void delete_sll(singly_linked_list *sll) {
	delete_list_one_way(&sll->head);

	if (sll->head != NULL) {
		free(sll->head);
	}

	sll->head_address = NULL;
	free(sll);
}

// * Utilities

// ** Change node name
void sll_set_name(Node *head, int value, char* name) {
	Node *temp = lookup_number(head, value);
	setName(temp, name);
}
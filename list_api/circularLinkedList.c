//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#include "circularLinkedList.h"

// * Create the list
circular_linked_list* create_circular_ll() {
	circular_linked_list *cll = malloc(sizeof(circular_linked_list));

	cll->head = NULL;
	cll->head_address = &cll->head;
	cll->size = 0;

	return cll;
}

// * Insert nodes
void cll_insert_front(circular_linked_list *cll, int value) {
	Node *new_node = createNode(value);

	if (new_node) {
		insert_front_two_way_circular(cll->head_address, new_node);
		cll->size++;
	}
}

void cll_insert_back(circular_linked_list *cll, int value) {
	Node *new_node = createNode(value);

	if (new_node) {
		insert_back_two_way_circular(cll->head_address, new_node);
		cll->size++;

	}
}

void cll_insert_back_name(circular_linked_list *cll, int value, char* name) {
	Node *new_node = createNode(value);

	if (new_node) {
		insert_back_two_way_circular(cll->head_address, new_node);
		cll->size++;

		setName(new_node, name);
	} else {
		printf("New node not created.\n");
	}
}
void cll_insert_back_recursive(circular_linked_list *cll, int value) {
	Node *new_node = createNode(value);

	if (new_node) {
		insert_back_two_way_circular(cll->head_address, new_node);
		cll->size++;
	}
}

// * Remove nodes
void cll_remove_by_name(circular_linked_list *cll, char* name) {

	Node *temp = lookup_name(cll->head, name);

	if (temp) {
		remove_by_name_two_way_circular(cll->head_address, name);
	}

}

void cll_remove_by_value(circular_linked_list *cll, int value) {
	Node *temp = lookup_number(cll->head, value);

	if (temp) {
		remove_by_value_two_way_circular(cll->head_address, value);
	}
}

// * Delete list
void delete_cll(circular_linked_list *cll) {
	if (cll != NULL) {
		delete_list_two_way_circular(cll->head_address);
		cll->head = NULL;
		cll->head_address = NULL;

		free(cll);
	}
}

// * Utilities

// ** Change node name
void cll_set_name(Node *head, int value, char* name) {
	Node* temp = lookup_number(head, value);

	setName(temp, name);
}

// ** Print circular list
void print_cll(Node *head) {

	if (head == NULL) {
		printf("(empty)\n");
	}
	else {
		Node* temp_head  = head;

		printf("[ ");

		do {
			printf("%s%s", temp_head->name, temp_head->next == head? " ]\n" : ", ");
			temp_head = temp_head->next;
		} while (temp_head != head);
	}
}

// ** Lookup
Node* cll_lookup_name(circular_linked_list* cll, char* name) {
	return lookup_name_circular(cll->head, name);
}

Node* cll_lookup_value(circular_linked_list* cll, int value) {
	return lookup_number_circular(cll->head, value);
}
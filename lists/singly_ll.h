//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_SINGLY_LL_H
#define LIB_SINGLY_LL_H

#include <stdio.h>

#include "../list_api/node.h"
#include "../list_api/singly_linked_list.h"

void find_president(Node *head, char* name);

void singly_ll(void) {

	printf("Presidential Singly Linked List\n\n");

	singly_linked_list* sll = create_singly_ll();

	// list is empty:
	print_list(sll->head);

	int iteration = 0;
	int recursion = 1;

	if (iteration) {
		sll_insert_front(sll, 1);
		sll_set_name(sll->head, 1, "George Washington");

		print_list(sll->head);

		sll_insert_back(sll, 4);
		sll_set_name(sll->head, 4, "James Madison");

		print_list(sll->head);

		sll_insert_back(sll, 16);
		sll_set_name(sll->head, 16, "Abraham Lincoln");

		print_list(sll->head);

		sll_insert_back(sll, 18);
		sll_set_name(sll->head, 18, "Ulysses S. Grant");

		sll_insert_back(sll, 28);
		sll_set_name(sll->head, 28, "Woodrow Wilson");

		print_list(sll->head);

		// Node search
		printf("\nNode search:\n");

		find_president(sll->head, "Abraham Lincoln");
		find_president(sll->head, "Shakira");

		// Removal of node
		printf("\nNode removal:\n");
		sll_remove_by_name(sll, "James Madison");
		print_list(sll->head);

		delete_sll(sll);
	}

	if (recursion) {
		sll_insert_front(sll, 1);
		sll_set_name(sll->head, 1, "George Washington");

		print_list_recursive(sll->head);

		sll_insert_back_recursive(sll, 4);
		sll_set_name(sll->head, 4, "James Madison");

		print_list_recursive(sll->head);

		sll_insert_back_recursive(sll, 16);
		sll_set_name(sll->head, 16, "Abraham Lincoln");

		print_list_recursive(sll->head);

		sll_insert_back_recursive(sll, 18);
		sll_set_name(sll->head, 18, "Ulysses S. Grant");

		sll_insert_back_recursive(sll, 28);
		sll_set_name(sll->head, 28, "Woodrow Wilson");

		print_list_recursive(sll->head);

		// Node search
		printf("\nNode search:\n");

		find_president(sll->head, "Abraham Lincoln");
		find_president(sll->head, "Shakira");

		// Removal of node
		printf("\nNode removal:\n");
		sll_remove_by_name(sll, "James Madison");
		print_list_recursive(sll->head);

		printf("List in reverse:\n");

		print_list_reverse_recursive(sll->head);

		delete_sll(sll);
	}

}

void find_president(Node *head, char* name) {

	Node *search = lookup_name(head, name);

	if (search) {
		printf("Found: President #%d, %s.\n", search->value, search->name);
	}
	else {
		printf("Not Found: %s is not a US President.\n", name);
	}
}

#endif //LIB_SINGLY_LL_H

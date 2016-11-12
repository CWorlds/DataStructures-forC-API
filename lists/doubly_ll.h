//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_DOUBLY_LL_H
#define LIB_DOUBLY_LL_H

#include <stdio.h>
#include <ctype.h>
#include "../list_api/doublyLinkedList.h"
#include "muffins.h"

void doubly_ll (void) {

	// Create Double Linked List
	doubly_linked_list *muffin_man = create_doubly_ll();
	print_list(muffin_man->head);

	init_steps_dll(&muffin_man);

	printf("These are the steps to prepare a muffin:\n");
	print_list(muffin_man->head);

	Node *step = muffin_man->head;

	int quit = 0;
	int init = 1;
	char phase;

	intro();

	while (!quit) {

		scanf("%c", &phase);
		while (getchar() != '\n');


		switch (phase) {
			case 'N':
			case 'n':
				if (!init) {
					if (next_step(&step))
					{
						instruction(step);
					}
				}
				else {
					instruction(step);
					init = 0;
				}
				printf("Enter your choice: ");
				break;
			case 'P':
			case 'p':
				if (!init) {
					if (undo_step(&step))
					{
						instruction(step);
					}
				} else {
					intro();
				}
				printf("Enter your choice: ");
				break;
			case 'Q':
			case 'q':
				quit = 1;
				break;
			default:
				invalid_choice();
				printf("Enter your choice: ");
				break;
		}
	}

	delete_dll(muffin_man);
}

#endif //LIB_DOUBLY_LL_H
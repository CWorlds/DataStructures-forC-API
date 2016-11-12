//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_CIRCULAR_LL_H
#define LIB_CIRCULAR_LL_H

#include "../list_api/circularLinkedList.h"
#include <stdio.h>
#include "muffins.h"

void circular_ll (void) {

	// Create Double Linked List
	circular_linked_list *muffin_man = create_circular_ll();
	print_cll(muffin_man->head);

	init_steps_cll(&muffin_man);

	printf("These are the steps to prepare a muffin:\n");
	print_cll(muffin_man->head);

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

	delete_cll(muffin_man);
}

#endif //LIB_CIRCULAR_LL_H

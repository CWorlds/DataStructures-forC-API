//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#include "muffins.h"

void print_step(Node *step) {
	printf("Step: (%d), %s...\n", step->value, step->name);
}

int undo_step(Node **step) {
	Node *temp = *step;

	if (temp->prev == NULL) {
		clear();
		banner();
		spacer();

		newLine();
		newLine();
		printf("You are at the beginning of the procedure.!\n");
		newLine();
		newLine();

		spacer();
		navigation_no_prev();
		return 0;
	}

	*step = temp->prev;
	return 1;
}

int next_step(Node **step) {
	Node *temp = *step;

	if (temp->next == NULL) {
		clear();
		banner();
		spacer();

		newLine();
		newLine();
		printf("There are no more steps left. You are done!");
		newLine();
		newLine();

		spacer();
		navigation_no_next();
		return 0;
	}
	*step = temp->next;
	return 1;
}

void init_steps_dll(doubly_linked_list **dll) {
	dll_insert_back_name(*dll, 1, "Choose a muffin recipe");
	dll_insert_back_name(*dll, 2, "Prep the muffin pan");
	dll_insert_back_name(*dll, 3, "Mix ingredients");
	dll_insert_back_name(*dll, 4, "Combine wet and dry ingredients quickly");
	dll_insert_back_name(*dll, 5, "Take care not to overmix the batter");
	dll_insert_back_name(*dll, 6, "Fill the muffin cups");
	dll_insert_back_name(*dll, 7, "Add toppings");
	dll_insert_back_name(*dll, 8, "Bake and cool muffins");
}

void init_steps_cll(circular_linked_list **cll) {
	cll_insert_back_name(*cll, 1, "Choose a muffin recipe");
	cll_insert_back_name(*cll, 2, "Prep the muffin pan");
	cll_insert_back_name(*cll, 3, "Mix ingredients");
	cll_insert_back_name(*cll, 4, "Combine wet and dry ingredients quickly");
	cll_insert_back_name(*cll, 5, "Take care not to overmix the batter");
	cll_insert_back_name(*cll, 6, "Fill the muffin cups");
	cll_insert_back_name(*cll, 7, "Add toppings");
	cll_insert_back_name(*cll, 8, "Bake and cool muffins");
}

void banner() {
	printf("**************************************************************************\n");
	printf("***************     @@@@@     EASY BAKE OVEN     @@@@@     ***************\n");
	printf("**************************************************************************\n");
}

void welcome() {
	spacer();

	newLine();
	printf("   LET'S MAKE SOME MUFFINS!\n");
	printf("   To navigate, when prompted, press (N) to move to the next step and\n");
	printf("   press (P) to move to the previous step.\n");
	newLine();

	spacer();
}

void navigation() {
	printf("**************************************************************************\n");
	printf("* <- Prev (P)       @@@@@        (Q) Quit        @@@@@       (N) Next -> *\n");
	printf("**************************************************************************\n");
}

void navigation_no_next() {
	printf("**************************************************************************\n");
	printf("* <- Prev (P)       @@@@@        (Q) Quit        @@@@@                   *\n");
	printf("**************************************************************************\n");
}

void navigation_no_prev() {
	printf("**************************************************************************\n");
	printf("*                   @@@@@        (Q) Quit        @@@@@       (N) Next -> *\n");
	printf("**************************************************************************\n");
}

void spacer() {
	printf("                                                                          \n");
	printf("                                                                          \n");
	printf("                                                                          \n");
}

void newLine() {
	printf("\n");
}

void clear() {
	int i;
	for (i = 0; i < 79; ++i)
	{
		newLine();
	}
}

void instruction(Node *step) {
	clear();
	banner();
	spacer();

	newLine();
	newLine();
	printf("   ");
	print_step(step);
	newLine();
	newLine();

	spacer();
	navigation();
}

void invalid_choice() {
	clear();
	banner();
	spacer();

	newLine();
	newLine();
	printf("   Invalid choice. Burn!\n");
	newLine();
	newLine();

	spacer();
	navigation();
}

void intro() {
	clear();
	banner();
	welcome();
	navigation_no_prev();
}
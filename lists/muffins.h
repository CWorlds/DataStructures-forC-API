//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_MUFFINS_H
#define LIB_MUFFINS_H

#include "../list_api/node.h"
#include "../list_api/circularLinkedList.h"
#include "../list_api/doublyLinkedList.h"

void print_step(Node *step);

int undo_step(Node **step);
int next_step(Node **step);

void init_steps_cll(circular_linked_list **cll);
void init_steps_dll(doubly_linked_list **dll);
void intro();
void banner();
void navigation();
void navigation_no_prev();
void navigation_no_next();
void spacer();
void newLine();
void welcome();
void instruction(Node *step);
void clear();
void invalid_choice();

#endif //LIB_MUFFINS_H

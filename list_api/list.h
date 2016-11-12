//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_LIST_H
#define LIB_LIST_H

#include "node.h"

// * Insert Node
void insert_front_one_way(Node **head, Node *node);
void insert_back_one_way(Node **head, Node *node);

void insert_front_two_way(Node **head, Node *node);
void insert_back_two_way(Node **head, Node *node);

void insert_back_recursive_one_way(Node **head, Node *node);
void insert_back_recursive_one_way_helper(Node *head, Node *node);

void insert_back_recursive_two_way(Node **head, Node *node);
void insert_back_recursive_two_way_helper(Node *head, Node *node);

void insert_front_two_way_circular(Node **head, Node *node);
void insert_back_two_way_circular(Node **head, Node *node);

// * Remove node

void remove_by_name_one_way(Node **head, char *name);
void remove_by_name_two_way(Node **head, char *name);

void remove_by_value_one_way(Node **head, int value);
void remove_by_value_two_way(Node **head, int value);

void remove_by_name_two_way_circular(Node **head, char* name);
void remove_by_value_two_way_circular(Node **head, int value);


// * Delete list

void delete_list_one_way(Node **head);
void delete_list_two_way(Node **head);
void delete_list_two_way_circular(Node **head);

// * Utilities

// ** Look up node

Node* lookup_name(Node *head, char* name);
Node* lookup_number(Node *head, int value);

Node* lookup_name_circular(Node *head, char* name);
Node* lookup_number_circular(Node *head, int value);

// ** Print list

void print_list(Node *head);
void print_list_recursive(Node *head);
void print_list_recursive_helper(Node *head);
void print_list_reverse_recursive(Node *head);
void print_list_reverse_recursive_helper(Node *head);

#endif //LIB_LIST_H

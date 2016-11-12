//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#include "list.h"
#include <string.h>

// * Insert Node

void insert_front_one_way(Node **head, Node *node) {
	if (head != NULL) {
		if (*head == NULL) {
			*head = node;
		}
		else {
			node->next = *head;
			*head = node;
		}
	}
	else {
		printf("Error: Pointer to head pointer is NULL.\n");
	}
}

void insert_back_one_way(Node **head, Node *node)  {

	if (head != NULL) {
		if (*head == NULL) {
			*head = node;
		}
		else {
			Node *temp_head = *head;
			for(; temp_head->next != NULL; temp_head = temp_head->next) {
				;
			}

			temp_head->next = node;
		}
	}
	else {
		printf("Error: Pointer to head pointer is NULL.\n");
	}
}

void insert_front_two_way(Node **head, Node *node) {

	if (head != NULL) {
		if (*head == NULL) {
			*head = node;
		}
		else {
			Node *temp;
			temp = *head;
			node->next = *head;
			temp->prev = *head;
		}
	}
	else {
		printf("Error: Pointer to head pointer is NULL.\n");
	}
}

void insert_back_two_way(Node **head, Node *node) {

	if (head != NULL) {
		if (*head == NULL) {
			*head = node;
		}
		else {
			Node *temp_head = *head;
			for (; temp_head->next != NULL; temp_head = temp_head->next) {
				;
			}
			temp_head->next = node;
			node->prev = temp_head;
		}
	}
	else {
		printf("Error: Pointer to head pointer is NULL.\n");
	}
}

void insert_front_two_way_circular(Node **head, Node *node) {
	if (head != NULL) {
		if (*head == NULL) {
			*head = node;
			node->prev = *head;
			node->next = *head;
		} else {
			Node *old_head = *head;

			*head = node;
			old_head->prev->next = *head;
			(*head)->prev = old_head->prev;
			(*head)->next = old_head;
			old_head->prev = *head;
		}
	}
}

void insert_back_two_way_circular(Node **head, Node *node) {

	if (head != NULL) {
		if (*head == NULL) {
			*head = node;
			node->next = *head;
		}
		else {
			Node *temp_head = *head;

			for (; temp_head->next != *head; temp_head = temp_head->next) {
				;
			}
			temp_head->next = node;
			node->prev = temp_head;
			node->next = *head;
			(*head)->prev = node;
		}
	}
	else {
		printf("Error: Pointer to head pointer is NULL.\n");
	}
}

void insert_back_recursive_one_way(Node **head, Node *node) {

	if (head != NULL) {
		insert_back_recursive_one_way_helper(*head, node);
	}
}

void insert_back_recursive_one_way_helper(Node *head, Node *node) {
	if (head->next == NULL) {
		head->next = node;
		return;
	}

	insert_back_recursive_one_way_helper(head->next, node);
}

void insert_back_recursive_two_way(Node **head, Node *node) {
	if (head != NULL) {
		insert_back_recursive_two_way_helper(*head, node);
	}
}
void insert_back_recursive_two_way_helper(Node *head, Node *node) {
	if (head->next == NULL) {
		head->next = node;
		node->prev = head;

		return;
	}

	insert_back_recursive_two_way_helper(head->next, node);
}


// * Remove node

void remove_by_name_one_way(Node **head, char *name) {
	Node *current = *head;
	Node *previous = NULL;

	if (*head != NULL)
	{
		for (; current != NULL; current = current->next) {
			if (strcmp(current->name, name) == 0) {
				if (current != *head) {
					previous->next = current->next;
				} else {
					*head = current->next;
				}
				free(current);
				break;
			}
			previous = current;
		}
	}
}

void remove_by_name_two_way(Node **head, char *name) {
	Node *current = *head;

	if (*head != NULL) {
		for (; current!= NULL; current = current->next) {
			if (strcmp(current->name, name) == 0) {
				if (current->prev != NULL) {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				} else {
					*head = current->next;
					current->next->prev = NULL;
					current->next = NULL;
				}
				free(current);
				break;
			}
		}
	}
}

void remove_by_value_one_way(Node **head, int value) {
	Node *current = *head;
	Node *previous = NULL;

	if (*head != NULL)
	{
		for (; current != NULL; current = current->next) {
			if (current->value == value) {
				if (current != *head) {
					previous->next = current->next;
				} else {
					*head = current->next;
				}
				free(current);
				break;
			}
			previous = current;
		}
	}
}

void remove_by_value_two_way(Node **head, int value) {
	Node *current = *head;

	if (*head != NULL) {
		for (; current!= NULL; current = current->next) {
			if (current->value == value) {
				if (current->prev != NULL) {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				} else {
					*head = current->next;
					current->next->prev = NULL;
					current->next = NULL;
				}
				free(current);
				break;
			}
		}
	}
}

void remove_by_name_two_way_circular(Node **head, char* name) {
	Node *current = *head;

	if (*head != NULL) {
		do {
			if (strcmp(current->name, name) == 0) {
				current->prev = current->next;
				current->next->prev = current->prev;
				current->prev->next = current->next;
				free(current);
				break;
			}
			current = current->next;
		} while (current != *head);
	}
}

void remove_by_value_two_way_circular(Node **head, int value) {
	Node *current = *head;

	if (*head != NULL) {
		do {
			if (current->value == value) {
				current->prev = current->next;
				current->next->prev = current->prev;
				current->prev->next = current->next;
				free(current);
				break;
			}
			current = current->next;
		} while (current != *head);
	}
}

// * Delete list

void delete_list_one_way(Node **head) {

	Node *current = *head;
	Node *temp = NULL;

	for (; current != NULL;) {
		temp = current;
		current = current->next;

		free(temp);
	}

	*head = current;
}

void delete_list_two_way(Node **head) {
	Node *current = *head;
	Node *temp;
	for (; current != NULL;) {
		temp = current;
		current = current->next;
		free(temp);
	}

	*head = current;
}

void delete_list_two_way_circular(Node **head) {
	Node *current = *head;
	Node *temp;

	if (*head != NULL) {
		do {
			temp = current;
			current = current->next;

			free(temp);

		} while (current != *head || current != NULL);
	}
}

// ** Look up node

Node* lookup_name(Node *head, char* name) {
	Node *temp_head = head;

	for (; temp_head != NULL; temp_head = temp_head->next) {
		if (strcmp(temp_head->name, name) == 0) {
			return temp_head;
		}
	}

	return NULL;
}

Node* lookup_number(Node *head, int value) {
	Node *temp_head = head;

	for (; temp_head != NULL; temp_head = temp_head->next) {
		if (temp_head->value == value) {
			return temp_head;
		}
	}

	return NULL;
}

Node* lookup_name_circular(Node *head, char* name) {
	Node *current = head;

	if (head != NULL) {
		do {
			if (strcmp(current->name, name) == 0) {
				return current;
			}
			current = current->next;
		} while (current != head);
	}

	return NULL;
}

Node* lookup_number_circular(Node *head, int value) {
	Node *current = head;

	if (head != NULL) {
		do {
			if (current->value == value) {
				return current;
			}
			current = current->next;
		} while (current != head);
	}

	return NULL;
}

// ** Print list

void print_list(Node *head) {

	if (head == NULL) {
		printf("(empty)\n");
	}
	else {
		Node* temp_head  = head;

		printf("[ ");

		for (; temp_head != NULL ; temp_head = temp_head->next)
		{
			printf("%s%s", temp_head->name, temp_head->next == NULL? " ]\n" : ", ");
		}
	}
}

void print_list_recursive(Node *head) {
	if (head == NULL) {
		printf("(empty)");
	}
	else {
		printf("[ ");
		print_list_recursive_helper(head);
	}
}

void print_list_recursive_helper(Node *head) {
	if (head == NULL) {
		return;
	}

	printf("%s%s", head->name, head->next == NULL? " ]\n" : ", ");
	print_list_recursive_helper(head->next);
}

void print_list_reverse_recursive(Node *head) {
	if (head == NULL) {
		printf("(empty)");
	} else {
		printf("[ ");
		print_list_reverse_recursive_helper(head);
	}
}

void print_list_reverse_recursive_helper(Node *head) {
	static int i = 0;

	if (head == NULL) {
		return;
	}

	i++;
	print_list_reverse_recursive_helper(head->next);
	i--;

	printf("%s%s", head->name, i == 0? " ]\n" : ", ");
}

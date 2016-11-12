//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#include "node.h"
#include <string.h>

Node* createNode(int value) {
	Node* new_node = malloc(sizeof(Node));

	if (new_node) {
		new_node->value = value;
		new_node->name = NULL;
		new_node->prev = NULL;
		new_node->next = NULL;

		return new_node;
	}
	else {
		return NULL;
	}
}

void printNode(const Node* node) {
	printf("Node value: %d\n", node->value);

	if (node->name != NULL) {
		printf("Node name: %s\n", node->name);
	}
	else
	{
		printf("Node name: N/A");
	}


	if (node->prev != NULL) {
		printf("Node previous value: %d\n", node->prev->value);
	}
	else {
		printf("Node previous value: N/A\n");
	}

	if (node->next != NULL) {
		printf("Node next value: %d\n", node->next->value);
	}
	else {
		printf("Node next value: N/A\n");
	}
}

void setName(Node* node, char* new_name)
{
	node->name = new_name;
//	strcpy(node->name, new_name);
}
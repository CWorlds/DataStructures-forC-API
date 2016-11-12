//
// Copyright (c) 2016 [Decahub]. All rights reserved.
//

#ifndef LIB_NODE_H
#define LIB_NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	char* name;
	struct Node* next;
	struct Node* prev;
} Node;

Node* createNode(int value);

void printNode(const Node* node);

void setName(Node* node, char name[]);

#endif //LIB_NODE_H

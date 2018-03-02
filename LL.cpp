// LL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
};
/*============================================================================*/
void insertList(node* n) {
	int d;
	cin >> d;
	if (d != '!') {
		n->data = d;
	}
	while (n != NULL) {
		cin >> d;
		if (d != -1) {
			node* newNode = new node;
			n->next = newNode;
			newNode->data = d;
		}
		else {
			n->next = NULL;
		}
		n = n->next;
	}
}
/*============================================================================*/
void printlist(node* n) {
	while (n != NULL) {
		cout << n->data << endl;
		n = n->next;
	}
}
/*============================================================================*/
void insertAfter(node *n, int d) {
	node* newNode = new node;
	newNode->data = d;
	newNode->next = n->next;
	n->next = newNode;
}
/*============================================================================*/
void push(node **h, int d) {
	node* newNode = new node;
	newNode->data = d;
	newNode->next = *h;
	*h = newNode;
}
/*============================================================================*/
int getSize(node *n) {
	int counter = 0;
	while (n != NULL) {
		counter++;
		n = n->next;
	}
	return counter;
}
/*============================================================================*/
void sortList(node* n) {
	int temp;
	node* nodeHolder = n;
	while (n->next != NULL) {
		while (n->next != NULL) {
			if (n->next->data < nodeHolder->data) {
				temp = nodeHolder->data;
				nodeHolder->data = n->next->data;
				n->next->data = temp;
			}
			n = n->next;
		}
		n = nodeHolder;
		n = n->next;
		nodeHolder = n;
	}
}

int main()
{
	/*node* base, *head, *second, *third;
	base = NULL;
	head = new node;
	second = new node;
	third = new node;
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	printlist(head);
	cout << "List consists of " << getSize(head) << " elements.\n";
	push(&head, 0);
	insertAfter(third, 8);*/
	node* head = new node;
	insertList(head);
	cout << "====================\n";
	sortList(head);
	printlist(head);
	cout << "List consists of " << getSize(head) << " elements.\n";
    return 0;
}


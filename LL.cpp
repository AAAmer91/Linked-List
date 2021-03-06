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
	if (d != -1) {
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
void printList(node* n) {
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
/*============================================================================*/
void insertSorted(node** n,int d) {
	//case: at the very first 
	if (d <= (*n)->data) {
		node* newNode = new node;
		newNode->data = d;
		newNode->next = *n;
		*n = newNode;
		return;
	}
	//case: in the middle 
	node* N = *n;
	while (N->next != NULL) {
		if (d <= N->next->data) {
			node* newNode = new node;
			newNode->data = d;
			newNode->next = N->next;
			N->next = newNode;
			return;
		}
		N = N->next;
	}
	//case: at the very last
	node* newNode = new node;
	newNode->data = d;
	newNode->next = NULL;
	N->next = newNode;
}
/*============================================================================*/
int nth_elementBackward(node* Node, int nth){
	node* shiftedNode = Node;

	for (int i = 0; i < nth; i++)
		shiftedNode = shiftedNode->next;
	while (shiftedNode != NULL) {
		shiftedNode = shiftedNode->next;
		Node = Node->next;
	}
	return Node->data;
}

int main()
{
	int n;
	node *head, *second, *third;
	head = new node;
	second = new node;
	third = new node;
	head->data = 9;
	head->next = second;
	second->data = 6;
	second->next = third;
	third->data = 4;
	third->next = NULL;
	push(&head, -2);
	insertAfter(third, 8);
	printList(head);
	cout << "List consists of " << getSize(head) << " elements.\n";
	/*node* head = new node;
	insertList(head);
	cout << "====================\n";*/
	sortList(head);
	insertSorted(&head, -10);
	printList(head);
	cout << "List consists of " << getSize(head) << " elements.\n";
	cin >> n;
	cout << n << "th element from tail is " << nth_elementBackward(head, n) << endl;
    return 0;
}


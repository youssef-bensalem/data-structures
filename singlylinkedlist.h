//SinglyLinkedList.h
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
struct Node {
	int data;
	Node* next;
};
struct List {
	Node* head;
	int size;
};

#endif // SINGLYLINKEDLIST_H

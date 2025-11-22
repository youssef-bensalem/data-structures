#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct Node {
int data;
Node* next;
Node* prev;
};
struct List {
Node* head;
Node* tail;
int size;
};

#endif // DOUBLYLINKEDLIST_H

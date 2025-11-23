#include "DoublyLinkedListMeth.h"
#include <new>
#include <iostream>
using namespace std;

Node* createNode(int value) {
  Node* node = new (nothrow) Node{value, nullptr, nullptr };
  if (!node) cout << "\nMemory allocation failed for node\n";
  return node;
}

void destroyNode(Node* node) {
	delete node;
}

bool isEmpty(const List& L) {
	return L.size == 0;
}

int listSize(const List& L) {
	return L.size;
}

bool isFull(const List& L) {
	Node* test = new (nothrow) Node;
	if (!test) return true;
	delete test;
	return false;
}

int insert(List* L, int e, int pos) {
  if (!L) return 0;
  if (pos < 1 || pos > L->size + 1) {
    cout << "\nInvalid position";
    return 0;
  }
  Node* n = createNode(e);
  if (!n) return 0;
  if (isEmpty(*L)) {
    L->head = n;
    L->tail = n;
  }
  
  else if (pos == 1) {
    n->next = L->head;
    L->head->prev = n;
    L->head = n;
  }
  else if (pos == L->size + 1) {
    n->prev = L->tail;
    L->tail->next = n;
    L->tail = n;
  }
  else {
    Node* prev = nullptr;
    Node* current = L->head;
    for (int i = 1; i < pos; i++) {
    prev = current;
    current = current->next;
    }
    prev->next = n;
    n->prev = prev;
    n->next = current;
    current->prev = n;
  }
  L->size++;
  return 1;
}

int removeAt(List* L, int pos) {
  if (!L || isEmpty(*L)) {
    cout << "\nList is empty";
    return 0;
  }
  if (pos < 1 || pos > L->size) {
    cout << "\nInvalid position";
    return 0;
  }
  Node* current;
  if (L->size == 1) {
    current = L->head;
    L->head = nullptr;
    L->tail = nullptr;
  }
  else if (pos == 1) {
    current = L->head;
    L->head = L->head->next;
    L->head->prev = nullptr;
  }
  else if (pos == L->size) {
    current = L->tail;
    L->tail = L->tail->prev;
    L->tail->next = nullptr;
  }
  else {
    Node* prevNode = nullptr;
    current = L->head; // node to remove
    for (int i = 1; i < pos; i++) {
    prevNode = current;
    current = current->next; }
    current->next->prev = prevNode;
    prevNode->next = current->next;
  }
  destroyNode(current);
  L->size--;
  return 1;
}

List createList() {
  return List{ nullptr, nullptr, 0 };
}

void destroyList(List* L) {
  if (!L) return;
  Node* current = L->head;
  while (current) {
    Node* temp = current;
    current = current->next;
    destroyNode(temp);
  }
  L->head = nullptr ;
  L->tail = nullptr;
  L->size = 0;
}

void displayList(const List& L) {
	if (isEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	Node* current = L.head;
	while (current) {
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

int getElement(const List& L, int pos) {
	if (isEmpty(L)) {
		cerr << "\nList is empty\n";
		return -1;
	}

	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return -1;
	}
	Node* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}

	return current->data;
}

List CopyList(const List& L) {
  List newList = createList();
  Node* current = L.head;
  Node* tail = nullptr; // keep track of last node in new list
  while (current) {
  Node* n = createNode(current->data);
  if (!n) {
    cerr << "\nMemory allocation failed while copying\n";
    destroyList(&newList);
    return createList();
  }
  n->prev = tail; // set previous pointer
  if (!newList.head) {
    newList.head = n;
  } 
  else {
    tail->next = n; // link previous node to new node
  }
  tail = n; // update tail
  current = current->next;
  }
  newList.tail = tail; // set tail of new list
  newList.size = L.size;
  return newList;
}

bool CompareLists(const List& L1, const List& L2) {
	if (L1.size != L2.size) return false;

	Node* p1 = L1.head;
	Node* p2 = L2.head;

	while (p1) {
		if (p1->data != p2->data) return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}

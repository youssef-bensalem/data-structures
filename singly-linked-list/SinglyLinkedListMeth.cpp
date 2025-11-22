#include "SinglyLinkedListMeth.h"
#include <new>
#include <iostream>
using namespace std;

Node* createNode(int value) {
	Node* node = new (nothrow) Node{ value, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
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
		cerr << "\nInvalid position";
		return 0;
	}
	Node* n = createNode(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}
	else {
		Node* prev = nullptr;
		Node* current = L->head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->next = current;
	}

	L->size++;
	return 1;
}

int removeAt(List* L, int pos) {
	if (!L || isEmpty(*L)) {
		cerr << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalid position";
		return 0;
	}
	Node* prev = nullptr;
	Node* current = L->head;
	if (pos == 1) {
		L->head = current->next;
	}
	else {
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
	}
	destroyNode(current);
	L->size--;
	return 1;
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

List createList() {
	return List{ nullptr, 0 };
}

void destroyList(List* L) {
	if (!L) return;
	Node* current = L->head;
	while (current) {
		Node* temp = current;
		current = current->next;
		destroyNode(temp);
	}
	L->head = nullptr;
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

List CopyList(const List& L) {
	List newList = createList();
	Node* current = L.head;
	Node* tail = nullptr;

	while (current) {
		Node* n = createNode(current->data);
		if (!n) {
			cerr << "\nMemory allocation failed while copying\n";
			destroyList(&newList);
			return createList();
		}

		if (!newList.head) {
			newList.head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
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

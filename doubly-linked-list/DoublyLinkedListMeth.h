#ifndef SINGLYLINKEDLISTMETH_H
#define SINGLYLINKEDLISTMETH_H

#include "DoublyLinkedList.h"

Node* createNode(int value);
void destroyNode(Node* node);

List createList();
void destroyList(List* L);
bool isEmpty(const List& L);
bool isFull(const List& L);
int listSize(const List& L);

int insert(List* L, int e, int pos);
int removeAt(List* L, int pos);
int getElement(const List& L, int pos);
void displayList(const List& L);

List CopyList(const List& L);
bool CompareLists(const List& L1, const List& L2);

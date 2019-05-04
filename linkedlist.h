#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

struct Node {
int data;
Node * next;

};

class LinkedList {
private:
Node * head;
Node * resetHead;
int count();
int sum();
void printList(Node * head);
void insertNode(Node * prev, int num);
void deleteNode(Node * head);
void resetNode(Node * resetHead);

public:
LinkedList();
~LinkedList();

void addtoFront(int n);
double average();
void writeInorder(string & file);
void writeReversed(string & file);

};
#endif

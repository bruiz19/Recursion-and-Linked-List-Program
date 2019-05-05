//Brandon Ruiz 890130156
//Section 02

//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct Node {
    int data;
    Node * next;
};

class LinkedList {
private:
    Node * head;
    Node * resetHead;
    int count(); // RECURSIVE
    int sum(); // RECURSIVE
    void insertNode(Node * prev, int num);
void printList(Node * head);
void deleteNode(Node * head);
void resetNode(Node * resetHead);

public:
    LinkedList();
    ~LinkedList(); // RECURSIVE
    void addToFront(int n);
    double average(); // uses sum and count functions
    void writeInorder(string & file);
    void writeReversed(string & file);
};
#endif // end linkedlist.h

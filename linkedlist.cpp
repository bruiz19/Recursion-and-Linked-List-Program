//Brandon Ruiz 890130156
//Section 02

#include "linkedlist.h"

LinkedList::LinkedList() {
head = nullptr;
}

LinkedList::~LinkedList() {
    // RECURSIVE
head = resetHead;
deleteNode(head);
}

int LinkedList::count() {
    // RECURSIVE
if(head == nullptr) {
return 0;

}

else {
head = head->next;
return (1 + count());

}

}

void LinkedList::addToFront(int n) {
Node *newNode = new Node;
if(head == nullptr) {
newNode->data = n;
head = newNode;
return;

}

Node * prev = nullptr;
for(prev = head; prev != nullptr; prev = prev->next) {
if(n < head->data) {
newNode->data = n;
newNode->next = head;
head = newNode;
return;

}

else if(prev->next == nullptr) {
newNode->data = n;
prev->next = newNode;
return;

}

else if(n >= prev->data && prev->next != nullptr && n < prev->next->data) {
insertNode(prev, n);
return;

}

}

}

double LinkedList::average() {
    // uses sum and count functions
resetHead = head;
int sumofList = sum();
resetNode(resetHead);
int size = count();
resetNode(resetHead);
return (double(sumofList) / double(size));
}

int LinkedList::sum() {
    // RECURSIVE
if(head->next != nullptr) {
head = head->next;
return (head->data + sum());

}

else {
return resetHead->data;

}

}

void LinkedList::writeInorder(string & file) {
ofstream myFile;
Node * write = head;
myFile.open(file, ofstream::app);
while(write != nullptr) {
myFile << write->data << " ";
write = write->next;
}

myFile.close();

}

void LinkedList::writeReversed(string & file) {
    // RECURSIVE
ofstream myFile;
myFile.open(file, ofstream::app);
if(head->next == nullptr) {
myFile << endl << head->data << " ";
myFile.close();
return;
}

else {
myFile << head->data << " ";
head = head->next;
writeReversed(file);
return;
}

}


void LinkedList::printList(Node * head) {
for(Node *testA = head; testA != nullptr; testA = testA->next) {
cout << testA->data << " ";
}

cout << endl;
}

void LinkedList::insertNode(Node * prev, int num) {
Node *newNode = new Node;
newNode->data = num;
newNode->next = prev->next;
prev->next = newNode;
return;
}

void LinkedList::deleteNode(Node* head) {
if(head->next == nullptr) {
delete head;
return;
}

else {
deleteNode(head->next);
delete head;
}

}

void LinkedList::resetNode(Node * resetHead) {
head = resetHead;
}


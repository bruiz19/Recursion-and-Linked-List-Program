#include "linkedlist.h"
#include <iostream>
#include <string>
#include <fstream>

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
			return 1 + count();
		}
}

void LinkedList::addToFront(int n) {
Node *newNode = new Node;

	if(head == nullptr) {
		newNode->data = n;
		head = newNode;
		return;
	}

	Node *prev = nullptr;
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
		int sumOfList = sum();
		resetNode(resetHead);
		int size = count();
		resetNode(resetHead);
		return (double(sumOfList) / double(size));
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
	ofstream writeData;
	Node *write = head;
	writeData.open(file, ofstream::app);
	while(write != nullptr) {
		writeData << write->data << " ";
		write = write->next;
	}
	writeData.close();
}

void LinkedList::writeReversed(string & file) {
		// RECURSIVE
		ofstream writeData;
		writeData.open(file, ofstream::app);
		if(head->next == nullptr) {
			writeData << endl << head->data << " ";
			writeData.close();
			return;
		}
		else {
			writeData << head->data << " ";
			head = head->next;
			writeReversed(file);
			return;
		}
}

void LinkedList::printList(Node* head) {
	for(Node *testA = head; testA != nullptr; testA = testA->next) {
		cout << testA->data << " ";
	}
	cout << endl;
}

void LinkedList::insert(Node* prev, int num) {
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

void LinkedList::resetNode(Node* resetHead) {
	head = resetHead;
}

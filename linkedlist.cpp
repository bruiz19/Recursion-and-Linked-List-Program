#include "linkedlist.h"
#include <iostream>
#include <string>
#include <fstream>

linkedlist::linkedlist() {
	head = nullptr;
}

linkedlist::~linkedlist() {
		// RECURSIVE
		head = headBackup;
		deleteNode(head);
}

int linkedlist::count() {
		// RECURSIVE
		if(head == nullptr) {
			return 0;
		}
		else {
			head = head->next;
			return 1 + count();
		}
}

void linkedlist::addToFront(int n) {
	node *newNode = new node;

	if(head == nullptr) {
		newNode->data = n;
		head = newNode;
		return;
	}

	node *prev = nullptr;
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
			insert(prev, n);
			return;
		}
	}
}

double linkedlist::average() {
		// uses sum and count functions
		headBackup = head;
		int sumOfList = sum();
		resetHead(headBackup);
		int size = count();
		resetHead(headBackup);
		return (double(sumOfList) / double(size));
}

int linkedlist::sum() {
		// RECURSIVE
		if(head->next != nullptr) {
			head = head->next;
			return (head->data + sum());
		}
		else {
			return headBackup->data;
		}
}

void linkedlist::writeInorder(string & file) {
	ofstream writeData;
	node *write = head;
	writeData.open(file, ofstream::app);
	while(write != nullptr) {
		writeData << write->data << " ";
		write = write->next;
	}
	writeData.close();
}

void linkedlist::writeReversed(string & file) {
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

void linkedlist::printList(node* head) {
	for(node *testA = head; testA != nullptr; testA = testA->next) {
		cout << testA->data << " ";
	}
	cout << endl;
}

void linkedlist::insert(node* prev, int num) {
	node *newNode = new node;
	newNode->data = num;
	newNode->next = prev->next;
	prev->next = newNode;
	return;
}

void linkedlist::deleteNode(node* head) {
	if(head->next == nullptr) {
		delete head;
		return;
	}
	else {
		deleteNode(head->next);
		delete head;
	}
}

void linkedlist::resetHead(node* headBackup) {
	head = headBackup;
}

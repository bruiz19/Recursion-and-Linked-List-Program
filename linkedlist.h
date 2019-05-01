#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

using namespace std;

struct node {
	int data;
	node * next;
};

class linkedlist {
private:
	node * head;
	node * headBackup;
	//int inline count(); // RECURSIVE
	int count(); // RECURSIVE
	//int inline sum(); // RECURSIVE
	int sum(); // RECURSIVE
	//void inline printList(node* head);
	void printList(node* head);
	//void inline insert(node* prev, int num);
	void insert(node* prev, int num);
	//void inline deleteNode(node* head);
	void deleteNode(node* head);
	//void inline resetHead(node* headBackup);
	void resetHead(node* headBackup);

public:
	//inline linkedlist();
	linkedlist();
	//inline ~linkedlist(); // RECURSIVE
	~linkedlist(); // RECURSIVE
	//void inline addToFront(int n);
	void addToFront(int n);
	//double inline average(); // uses sum and count functions
	double average(); // uses sum and count functions
	//void inline writeInorder(string & file);
	void writeInorder(string & file);
	//void inline writeReversed(string & file);
	void writeReversed(string & file);
};
#endif // end linkedlist.h

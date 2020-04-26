#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Clock.h"

using namespace std;

struct Node {
	Node* parent, * leftChild, * rightChild;
	int value;
};

class BSTree{
	int size;
	Node* root;

public:
	BSTree();
	~BSTree();

	string cr, cl, cp;

	Node* getRoot();
	int getSize();
	
	void show(string sp, string sn, Node* root);
	Node* findElement(Node* node, int value);
	void readFromFile(string fileName);

	void removeTree(Node* node);

	void addElement(int value);
	Node* removeElement(int value);

	Node* next(Node* node);
	Node* before(Node* node);
	Node* minNode(Node* node);
	Node* maxNode(Node* node);
	Node* removeNode(Node* node);

	Node* turnRight(int value);
	Node* turnLeft(int value);

	void rotateLeft(Node* node);
	void rotateRight(Node* node);

	void rebalance();

	void makeExample(int size);
	void makeTests();
};


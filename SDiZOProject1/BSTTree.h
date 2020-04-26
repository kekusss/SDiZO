#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Clock.h"

using namespace std;

class BSTTree
{
	int size;
	int maxSize;
	int* array;

	int parent(int index);
	int leftChild(int index);
	int rightChild(int index);

	void swap(int* elem1, int* elem2);

public:
	BSTTree(int maxSize);
	~BSTTree();

	void show();
	int findElement(int value);
	void readFromFile(string fileName);

	void add(int value);
	void remove(int value);
	void fixDown(int index);
	void fixUp(int index);

	void makeExample(int size, int maxSize);
	void makeTests();
};


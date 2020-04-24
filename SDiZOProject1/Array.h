#pragma once

#include <String>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class Array
{
private: 
	int* elementPtr;
	int size;

public:
	Array();
	~Array();

	int getSize();

	void show();
	void readFromFile(string fileName);

	void addElementFirst(int element);
	void addElementLast(int element);
	void addElement(int element, int index);

	void removeValue(int value);
	void removeFirst();
	void removeLast();
	void remove(int index);

	bool findElement(int value);
	void makeExample(int eSize);
	void makeTests();

};


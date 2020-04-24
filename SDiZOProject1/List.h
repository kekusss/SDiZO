#pragma once

#include <String>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class List
{
private:
	int* head, tail;
	int element, size;

public:
	List();
	~List();

	int getSize();

	void show();
	void readFromFile(string fileName);

	void addElementFirst(int element);
	void addElementLast(int element);
	void addElement(int element, int index);

	void removeFirst();
	void removeLast();
	void remove(int index);

	int findElement(int value);
	void makeExample(int eSize);
	void makeTests();

};

